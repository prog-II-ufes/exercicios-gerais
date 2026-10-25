#!/bin/bash

## Definição de arquivos e pastas importantes
CONFIG_FILE='configuracoes'
DIR_RESPOSTAS=Respostas
DIR_RESULTADOS=Resultados
DIR_GAB_SRC="Gabarito-src"
DIR_GAB_OBJ="Gabarito-obj"
DIR_GAB_INCLUDES="Includes"
DIR_GAB_CASOS=Casos
DIR_INCLUDES=Includes

declare -A pesos_arquivos=()
declare -A pesos_testes=()
declare -A notas_testes=()
declare -A notas_alunos=()
declare -A stats_alunos=()
declare -A nota_final_aluno=()
declare -A string_nota_bc_aluno=()

ARQUIVO_JSON_SAIDA="saida.json"
JSON_SAIDA=""
IGNORE_VALGRIND=true
IGNORE_RESULTS=false
FIXED_INTERFACE=false
MAIN_AGRUPADA=false
REDIRECT_STDOUT=true
CONTINUE_RESULTS=false
TERMINAL_OUTPUT_LOG=""
peso_total_arquivos=0
config_file_names=()
config_test_names=()
# config_bin_file_names=()
nomes_alunos=()
string_nota_bc=""
config_section=0
valgrind_desconto=0
# nota_final=0
n_files=0
n_cases=0
n_linkings=0
TIMEOUT=5
ARQ_ALUNO_SAIDA="resultado.txt"

echo_e_salva_log() {
    echo -e "$1"
    TERMINAL_OUTPUT_LOG="${TERMINAL_OUTPUT_LOG}$1\n"
}

salva_json_saida() {
    JSON_SAIDA="${JSON_SAIDA}{\n"
    JSON_SAIDA="${JSON_SAIDA}\t\"alunos\": [\n"
    students_number=${#nomes_alunos[@]}
    for (( i=0; i<students_number; i++ )); do
        nome_aluno=${nomes_alunos[$i]}
        # for nome_aluno in ${nomes_alunos[@]}; do
        JSON_SAIDA="${JSON_SAIDA}\t\t{\n"
        #Insira abaixo o que você quer adicionar como saída do script, no formato "key":"value"
        #Siga o formato abaixo (substitua Nome pela chave e ${nome_aluno} pela variável que você quer salvar)
        # Idealmente, mantenha o primeiro campo como sendo o Nome, para a função de leitura abaixo funcionar corretamente
        JSON_SAIDA="${JSON_SAIDA}\t\t\t\"Nome\":\"${nome_aluno}\",\n"
        # O último campo não pode ter a vírgula antes do \n, se não sai do formato JSON
        # (e aí ferramentas de leitura JSON não conseguirão ler)
        JSON_SAIDA="${JSON_SAIDA}\t\t\t\"Nota\":${nota_final_aluno[$nome_aluno]}\n"
        #
        if (( $i != $students_number-1 )); then
            JSON_SAIDA="${JSON_SAIDA}\t\t},\n"
        else
            JSON_SAIDA="${JSON_SAIDA}\t\t}\n"
        fi
    done
    JSON_SAIDA="${JSON_SAIDA}\t]\n"
    JSON_SAIDA="${JSON_SAIDA}}"
    echo -e $JSON_SAIDA > $ARQUIVO_JSON_SAIDA
}

# Copie a seção abaixo para ler o JSON gerado por esse script em outro lugar, usando bash
# Por exemplo, para usar no BOCA Online Contest Administrator.
# declare -A saida_script_correcao=()
# le_saida_script_correcao() {
#     # Em Python:
#     # import json
#     # f = open('saida.json')
#     # data = json.load(f)
#     dentro_struct_alunos=false
#     dentro_mesmo_aluno=false
#     while IFS= read -r line
#     do
#         if [[ $dentro_struct_alunos == true ]]; then
#             line=$(echo -e $line | sed -E 's/[ \n\t\r]//g' ) #Tira espaços, \n, \t, \r de $line
#             if [[ "$line" == "]" ]]; then
#                 dentro_struct_alunos=false
#                 continue
#             fi
#             if [[ "$line" == "{"* || "$line" == "}"* ]]; then
#                 continue
#             fi
#             line=$(echo $line | sed 's/\"//g')
#             readarray -d : -t par < <(printf '%s' "$line") #https://unix.stackexchange.com/a/519917
#             if [[ ${par[0]} == "Nome" ]]; then
#                 nome_aluno=${par[1]}
#             else
#                 saida_script_correcao["$nome_aluno,${par[0]}"]=${par[1]}
#             fi
#         fi
#         if [[ "$line" == *"\"alunos\": ["* ]]; then
#             dentro_struct_alunos=true
#         fi
#     done < <(grep . "${ARQUIVO_JSON_SAIDA}")
# }

le_arq_config () {
    if [[ -f "$CONFIG_FILE" ]]; then
        echo_e_salva_log "- Arquivo de configuração encontrado!"
        while IFS= read -r line
        do
            line=$(echo -e $line | sed -E 's/[ \n\t\r]//g' ) #Tira espaços, \n, \t, \r de $line
            if test "$line" == "Arquivos"; then
                config_section=1
                continue
            elif test "$line" == "Validações"; then
                config_section=2
                continue
            elif test "$line" == "Valgrind"; then
                config_section=3
                IGNORE_VALGRIND=false
                valgrind_desconto=0.5
                continue
            elif test "$line" == "Nota"; then
                config_section=4
                continue
            elif test "$line" == "InterfaceFixa"; then
                config_section=0
                FIXED_INTERFACE=true
                continue
            elif test "$line" == "IgnoraResultados"; then
                config_section=0
                IGNORE_RESULTS=true
                continue
            elif [[ "$line" ==  "LimiteTempo"* ]]; then
                config_section=0
                readarray -d= -t lines < <(printf '%s' "$line")
                TIMEOUT=${lines[1]}
                continue
            elif [[ "$line" ==  "NaoRedirecionaStdOut" ]]; then
                config_section=0
                REDIRECT_STDOUT=false
                continue
            elif [[ "$line" ==  "ContinuaCorrecao" ]]; then
                config_section=0
                CONTINUE_RESULTS=true
                continue    
            elif [[ "$line" ==  "MainAgrupada" ]]; then
                MAIN_AGRUPADA=true
                continue
            fi
            line=$(echo $line | cut -d'#' -f1 | cut -d';' -f1)

            if [[ ! -z "$line" ]]; then
                if test $config_section == 1; then
                    readarray -d = -t lines < <(printf '%s' "$line") #https://unix.stackexchange.com/a/519917
                    if [[ ! " ${config_file_names[*]} " =~ " ${lines[0]} " ]]; then
                        config_file_names+=(${lines[0]})
                    fi
                    pesos_arquivos+=([${lines[0]}]=${lines[1]})
                elif test $config_section == 2; then
                    readarray -d = -t lines < <(printf '%s' "$line")
                    if [[ ! " ${config_test_names[*]} " =~ " ${lines[0]} " ]]; then
                        config_test_names+=(${lines[0]})
                    fi
                    pesos_testes+=([${lines[0]}]=${lines[1]})
                elif test $config_section == 3; then
                    readarray -d = -t lines < <(printf '%s' "$line")
                    if [[ ${lines[0]} == 'desconto' ]]; then
                        valgrind_desconto=${lines[1]}
                    fi
                elif test $config_section == 4; then
                    string_nota_bc=$line
                fi
            fi
        done < <(grep . "${CONFIG_FILE}")
    else
        echo "- Arquivo de configuração não encontrado! "
        exit 1
    fi

    if [[ -z ${config_test_names} ]]; then
        echo "- Defina ao menos uma opção de "Validação" (Completo ou "Cruzamento" com algum TAD)! "
        exit 1
    fi

    if [[ " ${config_file_names[*]} " =~ " saida.txt " ]]; then
        if [ $REDIRECT_STDOUT = false ]; then
            echo "- O arquivo \"saida.txt\" é gerado através do redirecionamento da saída padrão, que está desativada."
            echo "- Retire o \"saida.txt\" dos arquivos OU desative a opção \"NaoRedirecionaStdOut\"."
            exit 1
        fi
    fi

    if [[ -z ${config_file_names} ]]; then
        echo "- Defina ao menos um arquivo de saida a ser comparado pelo script! "
        exit 1
    fi

    if [[ -z "$string_nota_bc" ]]; then
        string_nota_bc="0"
        for value in "${!pesos_testes[@]}"
        do
            string_nota_bc+="+$value"
        done
    fi

    for peso in "${pesos_arquivos[@]}"; do
        peso_total_arquivos=$(echo "scale=2; $peso_total_arquivos + $peso" | bc)
    done

    # echo ${config_file_names[@]}
    # echo ${pesos_arquivos[@]}
    # exit

}

calcula_nota_final() {
    # for nome_aluno in ${nomes_alunos[@]}; do
        nome_aluno=$1
        string_nota_bc_aluno[$nome_aluno]=$string_nota_bc
        for value in "${config_test_names[@]}"
        do
            string_nota_bc_aluno[$nome_aluno]=${string_nota_bc_aluno[$nome_aluno]//$value/(${notas_testes[$nome_aluno,$value]})}
        done
        # echo $string_nota_bc
        nota_final_aluno[$nome_aluno]=$(echo "scale=2; ${string_nota_bc_aluno[$nome_aluno]}" | bc -l)
    # done
}

cria_arquivo_resultado_aluno() {
    nome_aluno=$1
    STUDENT_RESULT_FOLDER=${DIR_RESULTADOS}/$student_name
    ARQ_ALUNO=$STUDENT_RESULT_FOLDER/$ARQ_ALUNO_SAIDA
    echo "Arquivos Esperados Corretos: ${stats_alunos[$nome_aluno,arquivos_corretos]} de $n_files" >> $ARQ_ALUNO
    echo "Pastas Compiladas Corretamente: ${stats_alunos[$nome_aluno,compilacoes_corretas]} de ${#config_test_names[@]} " >> $ARQ_ALUNO
    echo "Pastas Linkadas Corretamente: ${stats_alunos[$nome_aluno,linkagens_corretas]} de ${#config_test_names[@]}" >> $ARQ_ALUNO
    for nome_teste in ${config_test_names[@]}; do
        echo "Teste $nome_teste" >> $ARQ_ALUNO
        num_total_arquivos=$(( $n_cases * ${#config_file_names[@]} ))
        if [ "$IGNORE_RESULTS" = "false" ]; then
            echo "  - Resultados corretos: ${stats_alunos[$nome_aluno,$nome_teste,saidas_certas]} de $num_total_arquivos" >> $ARQ_ALUNO
        fi
        if [ "$IGNORE_VALGRIND" = "false" ]; then
            echo "  - Valgrinds corretos: ${stats_alunos[$nome_aluno,$nome_teste,valgrinds_certos]} de $n_cases" >> $ARQ_ALUNO
        fi
        echo "Nota de $nome_aluno para o teste $nome_teste: ${notas_testes[$nome_aluno,$nome_teste]}" >> $ARQ_ALUNO
    done
    echo "Nota de $nome_aluno: ${string_nota_bc_aluno[$nome_aluno]}" >> $ARQ_ALUNO
    echo "Nota de $nome_aluno: ${nota_final_aluno[$nome_aluno]}" >> $ARQ_ALUNO
}

imprime_resultados_e_cria_csv() {
    echo_e_salva_log "\n#######################################"
    echo_e_salva_log "RESULTADOS FINAIS"
    echo_e_salva_log "#######################################"


    # CSV file name
    csv_name="Resultado.csv"
    if [[ -f $csv_name ]]; then
        rm -r $csv_name
    fi
    # CSV header row
    header_csv_str="Nome"
    header_csv_created=false

    for nome_aluno in ${nomes_alunos[@]}; do
        # echo $aluno

        echo_e_salva_log "\n----------------------------------------------------------------------------"

        echo_e_salva_log "Aluno: $nome_aluno"

        content_csv_str="${nome_aluno}"

        echo_e_salva_log "  - Arquivos Esperados Corretos: ${stats_alunos[$nome_aluno,arquivos_corretos]} de $n_files"

        echo_e_salva_log "  - Pastas Compiladas Corretamente: ${stats_alunos[$nome_aluno,compilacoes_corretas]} de ${#config_test_names[@]} "

        echo_e_salva_log "  - Pastas Linkadas Corretamente: ${stats_alunos[$nome_aluno,linkagens_corretas]} de ${#config_test_names[@]}"



        for nome_teste in ${config_test_names[@]}; do

            echo_e_salva_log "  - Teste $nome_teste"

            header_csv_str=$header_csv_str",Resultado $nome_teste"

            num_total_arquivos=$(( $n_cases * ${#config_file_names[@]} ))

            if [ "$IGNORE_RESULTS" = "false" ]; then
                echo_e_salva_log "    - Resultados corretos: ${stats_alunos[$nome_aluno,$nome_teste,saidas_certas]} de $num_total_arquivos"

            fi
            if [ "$IGNORE_VALGRIND" = "false" ]; then
                echo_e_salva_log "    - Valgrinds corretos: ${stats_alunos[$nome_aluno,$nome_teste,valgrinds_certos]} de $n_cases"

            fi

            echo_e_salva_log "    - Nota de $nome_aluno para o teste $nome_teste: ${notas_testes[$nome_aluno,$nome_teste]}"

            content_csv_str=$content_csv_str",${notas_testes[$nome_aluno,$nome_teste]}"
        done

        echo_e_salva_log "  - Nota de $nome_aluno: ${string_nota_bc_aluno[$nome_aluno]}"


        echo_e_salva_log "  - Nota de $nome_aluno: ${nota_final_aluno[$nome_aluno]}"

        header_csv_str=$header_csv_str",Média"
        content_csv_str=$content_csv_str",${nota_final_aluno[$nome_aluno]}"

        if [[ "$header_csv_created" = "false" ]]; then
            echo $header_csv_str >> "$csv_name"
            header_csv_created=true
        fi
        echo $content_csv_str >> "$csv_name"
        content_csv_str=""
        header_csv_str=""

    done


    echo_e_salva_log "\n----------------------------------------------------------------------------"

    echo_e_salva_log "\nArquivo CSV $csv_name com os resultados finais foi gerado na pasta raíz!\n\n"

    echo -e $TERMINAL_OUTPUT_LOG > "log.txt"
}

executa_professor() {
    if test -d "$DIR_GAB_OBJ"; then
        rm -r $DIR_GAB_OBJ
    fi
    mkdir -p $DIR_GAB_OBJ
    echo_e_salva_log " - Pasta $DIR_GAB_OBJ criada com sucesso!"

    if test -d "$DIR_INCLUDES"; then
        rm -r $DIR_INCLUDES
    fi
    mkdir -p $DIR_INCLUDES
    echo_e_salva_log " - Pasta $DIR_INCLUDES criada com sucesso!"

    gab_src_files_names=()
    # Check if the folder exists and is a directory
    if [ -d "$DIR_INCLUDES" ] && [ -d "$DIR_GAB_SRC" ]; then
        # Use the find command to search for .h files within the folder
        HEADER_FILES=$(find "$DIR_GAB_SRC" -maxdepth 1 -type f -name "*.h")
        if [ -z "$HEADER_FILES" ]; then
            HEADER_FILES_EXIST=false
        else
            HEADER_FILES_EXIST=true
            if [[ " ${HEADER_FILES[*]} " =~ "completo.h" ]]; then
                echo_e_salva_log " - Não é permitido ter arquivos 'completo.c/.h' nesta versão do script! Mude o nome e execute novamente. "
                exit 1
            fi
        fi

        if [ "$HEADER_FILES_EXIST" = "true" ]; then
            for fileH in "${HEADER_FILES[@]}"; do
                cp $fileH $DIR_INCLUDES
            done
            echo_e_salva_log " - Arquivos .h do professor da pasta $DIR_GAB_SRC copiados para a pasta $DIR_INCLUDES com sucesso!"
        else
            echo_e_salva_log " - Não existem arquivos header na pasta $DIR_GAB_SRC do professor."
        fi

        src_files_array=()
        # Read the files with the specific extension into the array
        while IFS= read -r -d '' file; do
            src_files_array+=("$file")
        done < <(find "$DIR_GAB_SRC" -type f -name "*.c" -print0)
        if [[ " ${src_files_array[*]} " =~ "completo.c" ]]; then
            echo_e_salva_log " - Não é permitido ter arquivos 'completo.c/.h' nesta versão do script! Mude o nome e execute novamente. "
            exit 1
        fi
        # Print the elements of the array for verification
        for src_file in "${src_files_array[@]}"; do

            x=${src_file%.c}  # x sera' o nome do arquivo sem a extensao .c
            raw_file_name=${x##*/}  # raw_file_name sera' o nome do arquivo puro, sem os diretorios que contem ele
            #echo "raw_file_name: $raw_file_name"
            # if "$raw_file_name.h" || [[ "$raw_file_name" == "main" ]] ; then
                gab_src_files_names+=("$raw_file_name")
                src=$DIR_GAB_SRC/$raw_file_name.c
                out=$DIR_GAB_OBJ/$raw_file_name.o
                output=$(gcc -Wall -c $src -o $out 2>&1)
                if [ $? -ne 0 ]; then
                    echo_e_salva_log "   - Erro de compilação! Verifique se o arquivo $src está correto."
                    echo $TERMINAL_OUTPUT_LOG >> "log.txt"
                    exit 1
                fi
            # fi
        done

        output=$(gcc -Wall -o $DIR_GAB_OBJ/prog $DIR_GAB_OBJ/*.o -lm 2>&1)
        if [ $? -ne 0 ]; then
            echo_e_salva_log "   - Arquivos Linkados: Erro! Binário prog não gerado."
            echo $TERMINAL_OUTPUT_LOG >> "log.txt"
            exit 1
        else
            echo_e_salva_log " - Arquivos objetos do gabarito gerados com sucesso na pasta $DIR_GAB_OBJ!"
        fi

        if [[ $MAIN_AGRUPADA == true ]] ; then
            if [[ "$FIXED_INTERFACE" == true ]]; then
                echo_e_salva_log " - A opção "MainAgrupada" não deve ser usada junta com a opção InterfaceFixa !"
                exit 1
            fi
            if [[  ! " ${config_test_names[*]} " =~ "main" ]]; then
                echo_e_salva_log " - A opção "MainAgrupada" deve levar em consideração a validação \"main\"! Insira ela, mesmo que com peso zero!"
                exit 1
            fi

            echo_e_salva_log " - Apagando .c/.h/.o não listados no arquivo de configuração e gerando um código objeto único \"main.o\" com todos eles!"

            while IFS= read -r -d '' file; do
                file_sem_ext="${file%.*}"
                file_sem_ext=$(basename $file_sem_ext)
                if [[ ! " ${config_test_names[*]} " =~ "${file_sem_ext}" ]]; then
                    rm $file
                fi
            done < <(find "$DIR_GAB_OBJ" -type f -name "*.o" -print0)

            src_files_escondidas=""
            while IFS= read -r -d '' file; do
                file_sem_ext="${file%.*}"
                file_sem_ext=$(basename $file_sem_ext)
                if [[ ! " ${config_test_names[*]} " =~ "${file_sem_ext}" ]]; then
                    src_files_escondidas+="-include $file "
                fi
            done < <(find "$DIR_GAB_SRC" -type f -name "*.c" -print0)
            output=$(gcc -Wall -c ${src_files_escondidas[@]} $DIR_GAB_SRC/main.c -o $DIR_GAB_OBJ/main.o 2>&1)


            if [ $? -ne 0 ]; then
                echo_e_salva_log "   - Erro na geração do arquivo \"main.o\" com os códigos agrupados."
                echo $TERMINAL_OUTPUT_LOG >> "log.txt"
                exit 1
            else
                echo_e_salva_log " - Arquivos objetos do gabarito gerados com sucesso na pasta $DIR_GAB_OBJ!"
            fi

            while IFS= read -r -d '' file; do
                file_sem_ext="${file%.*}"
                file_sem_ext=$(basename $file_sem_ext)
                if [[ ! " ${config_test_names[*]} " =~ "${file_sem_ext}" ]]; then
                    rm $file
                fi
            done < <(find "$DIR_INCLUDES" -type f -name "*.h" -print0)
            
        fi

    else
        echo_e_salva_log " - Pasta não encontrada: $DIR_INCLUDES ou $DIR_GAB_SRC, abortado!"
        echo $TERMINAL_OUTPUT_LOG >> "log.txt"
        exit 1
    fi

    for DIR_CASE in "$DIR_GAB_CASOS"/*; do

        dir_saida=${DIR_CASE}/saida
        if [ ! -d "$dir_saida" ]; then
            mkdir -p $dir_saida
        fi

        txt_output_file=$(find "$DIR_CASE/saida" -maxdepth 1 -type f -name "*.txt" | head -n 1)
        if test -f "$txt_output_file"; then
            rm $DIR_CASE/saida/*.txt
        fi

        input_file=${DIR_CASE}/entrada.txt
        # output="${DIR_CASE}/saida/out_${filename_no_ext}.txt"
        output="${DIR_CASE}/saida/saida.txt"

        $DIR_GAB_OBJ/prog ${DIR_CASE} < $input_file > $output 2>&1

        echo_e_salva_log " - Output do resultado do professor gerado com sucesso na pasta $DIR_CASE/saida."

    done

    echo_e_salva_log " - Todos os arquivos necessários do professor gerados. Remova a pasta $DIR_GAB_SRC e envie o script para o Aluno!\n"

}

executa_aluno() {
    # Confere se há headers na pasta include
    if test -d "$DIR_INCLUDES"; then
            if find "$DIR_INCLUDES" -maxdepth 1 -type f -name "*.h" | read; then
                HEADER_FILES_EXIST=true
            fi
    fi
    if [ "$HEADER_FILES_EXIST" = "true" ]; then
        if [ -d "$DIR_INCLUDES" ]; then
            if [ $(find "$DIR_INCLUDES" -maxdepth 1 -type f -name "*.h" | wc -l) -gt 0 ]; then
                echo_e_salva_log " - Arquivos header necessários do professor existem na pasta $DIR_INCLUDES"
            else
                echo_e_salva_log " - Arquivos header necessários do professor não existem na pasta $DIR_INCLUDES, por favor rode o script do professor primeiro. Abortado!"
                echo $TERMINAL_OUTPUT_LOG >> "log.txt"
                exit 1
            fi
        else
            echo_e_salva_log " - A pasta $DIR_INCLUDES com os arquivos header do professor não existe, por favor rode o script do professor primeiro. Abortado!"
            echo $TERMINAL_OUTPUT_LOG >> "log.txt"
            exit 1
        fi
    fi
    # Confere se há objetos na pasta Gabarito-obj
    if [ -d "$DIR_GAB_OBJ" ]; then
        if [ $(find "$DIR_GAB_OBJ" -maxdepth 1 -type f -name "*.o" | wc -l) -gt 0 ]; then
            echo_e_salva_log " - Arquivos objetos necessários do professor existem na pasta $DIR_GAB_OBJ."

        else
            echo_e_salva_log " - Arquivos objetos necessários do professor não existem na pasta $DIR_GAB_OBJ, por favor rode o script do professor primeiro. Abortado!"

            echo $TERMINAL_OUTPUT_LOG >> "log.txt"
            exit 1
        fi
    else
        echo_e_salva_log " - A pasta $DIR_GAB_OBJ com os arquivos objetos do professor não existe, por favor rode o script do professor primeiro. Abortado!"

        echo $TERMINAL_OUTPUT_LOG >> "log.txt"
        exit 1
    fi

    # Conta quantos casos de teste existem
    n_cases=0
    for DIR_CASE in "$DIR_GAB_CASOS"/*; do
        (( n_cases++ ))
    done

    # Confere se há pasta Respostas. Se houver, cria pasta resultados.
    if [ -d "$DIR_RESPOSTAS" ]; then
        if [ -z "$(ls -A $DIR_RESPOSTAS)" ]; then
            echo_e_salva_log " - Erro! Por favor, crie uma pasta com o seu nome dentro da pasta Respostas/, por exemplo Respostas/JoaoAugusto/ e dentro dessa pasta do seu nome coloque os seus arquivos do código fonte."
            exit 1
        fi

        if [ ! -d "$DIR_RESULTADOS" ]; then
            mkdir -p $DIR_RESULTADOS
        fi
    else
        echo_e_salva_log "\nPasta não encontrada: $DIR_RESPOSTAS\n - Erro! Por favor, crie uma pasta chamada Respostas/ na raíz onde esta o Script e dentro desta pasta crie outra com o seu nome, por exemplo Respostas/JoaoAugusto/ e dentro dessa pasta do seu nome coloque os seus arquivos do código fonte."
        exit 1
    fi

    # Create empty arrays
    declare -a src_files_names

    for filepath in "$DIR_GAB_OBJ/"*.o; do
        if [[ -f "$filepath" ]]; then
            filename=$(basename "$filepath" .o)
            src_files_names+=("$filename")
            (( n_files++ ))
        fi
    done

    for headerpath in "$DIR_INCLUDES/"*.h; do
        if [[ -f "$headerpath" ]]; then
            # Extract just the file name without the path and extension
            (( n_files++ ))
        fi
    done

    iteration=0

    # Calcula número de testes a serem feitos
    n_folders_to_compile=${#pesos_testes[@]} # Completo é incluso por padrão na leitura das configurações, mas tem peso 0
    n_tests=$(( $n_folders_to_compile * $n_cases ))
    # echo $peso_total_arquivos
    nota_max_por_teste=$(echo "scale=2; $n_cases * $peso_total_arquivos" | bc )

    while IFS= read -r -d '' STUDENT_ANSWER_FOLDER; do
        if [ -d "$STUDENT_ANSWER_FOLDER" ]; then
            (( iteration++ ))

            

            # Get the student name
            delimiter="/" # Set the delimiter
            original_IFS="$IFS" # Save the old IFS
            IFS="$delimiter" # Set the IFS to the delimiter to split the string
            read -r _ student_name <<< "$STUDENT_ANSWER_FOLDER" # Read the second part of the string into a variable
            IFS="$original_IFS"

            echo_e_salva_log "\n#######################################"
            echo_e_salva_log "ALUNO: $student_name"
            echo_e_salva_log "#######################################\n"

            nomes_alunos+=($student_name)

            if [ -f ${DIR_RESULTADOS}/$student_name/$ARQ_ALUNO_SAIDA ] && [ $CONTINUE_RESULTS == true ]; then
                echo_e_salva_log "  - Configuração 'ContinuaAnalise' ligada e pasta $student_name já foi processada. Passando para o próximo aluno..."
                sscanf() { #https://stackoverflow.com/a/65055661
                    local str="$1"
                    local format="$2"
                    [[ "$str" =~ $format ]]
                }

                lines=()
                while IFS= read -r line
                do
                    lines+=("$line")
                done < "${DIR_RESULTADOS}/$student_name/$ARQ_ALUNO_SAIDA"
                index=0

                sscanf "${lines[index]}" "Arquivos Esperados Corretos: (.*) de (.*)"
                stats_alunos["$student_name,arquivos_corretos"]=${BASH_REMATCH[1]}
                (( index++ ))
                sscanf "${lines[index]}" "Pastas Compiladas Corretamente: (.*) de (.*)"
                stats_alunos["$student_name,compilacoes_corretas"]=${BASH_REMATCH[1]}
                (( index++ ))
                sscanf "${lines[index]}" "Pastas Linkadas Corretamente: (.*) de (.*)"
                stats_alunos["$student_name,linkagens_corretas"]=${BASH_REMATCH[1]}
                (( index++ ))
                for (( num_test=1; num_test<=${#config_test_names[@]} ; num_test ++ )); do
                    sscanf "${lines[index]}" "Teste (.*)"
                    nome_teste=${BASH_REMATCH[1]}
                    (( index++ ))
                    if [ "$IGNORE_RESULTS" = "false" ]; then
                        sscanf "${lines[index]}" "  - Resultados corretos: (.*) de (.*)"
                        stats_alunos["$student_name,$nome_teste,saidas_certas"]=${BASH_REMATCH[1]}
                        num_total_arquivos=${BASH_REMATCH[2]}
                        (( index++ ))
                    fi
                    if [ "$IGNORE_VALGRIND" = "false" ]; then
                        sscanf "${lines[index]}" "  - Valgrinds corretos: (.*) de (.*)"
                        stats_alunos["$student_name,$nome_teste,valgrinds_certos"]=${BASH_REMATCH[1]}
                        (( index++ ))
                    fi
                    sscanf "${lines[index]}" "Nota de (.*) para o teste (.*): (.*)"
                    notas_testes["$student_name,$nome_teste"]=${BASH_REMATCH[3]}
                    (( index++ ))
                done
                sscanf "${lines[index]}" "Nota de (.*): (.*)"
                string_nota_bc_aluno["$student_name"]=${BASH_REMATCH[2]}
                (( index++ ))
                sscanf "${lines[index]}" "Nota de (.*): (.*)"
                nota_final_aluno["$student_name"]=${BASH_REMATCH[2]}
                (( index++ ))
                
                continue
            fi

            

            ##########################################
            # criando os diretorios de resultados para cada aluno
            ##########################################
            echo_e_salva_log "CRIANDO O DIRETÓRIO DE RESULTADO PARA $student_name:"

            # create a directory in the Resultados folder with the student name and copy the content to there
            STUDENT_RESULT_FOLDER=${DIR_RESULTADOS}/$student_name
            if test -d "$STUDENT_RESULT_FOLDER"; then
                rm -r $STUDENT_RESULT_FOLDER
                sleep 1
            fi
            mkdir -p $STUDENT_RESULT_FOLDER
            if test -d "$STUDENT_RESULT_FOLDER"; then
                echo_e_salva_log " - Diretório $STUDENT_RESULT_FOLDER criado com sucesso!"

            fi
            for src_file_name in "${config_test_names[@]}"; do
                FILE_NAME_FOLDER=$STUDENT_RESULT_FOLDER/$src_file_name
                mkdir -p $FILE_NAME_FOLDER
                if test -d "$FILE_NAME_FOLDER"; then
                    echo_e_salva_log " - Diretório $FILE_NAME_FOLDER criado com sucesso!"

                fi
            done
            echo_e_salva_log " - Arquivos criados: ok!"

            ##########################################
            # verifica se os arquivos esperados existem
            ##########################################
            echo_e_salva_log "\nCHECKANDO OS ARQUIVOS DO ALUNO:"

            student_files_missing=0
            student_files_found=0
            for src_file_name in "${src_files_names[@]}"; do
                student_src=$STUDENT_ANSWER_FOLDER/$src_file_name.c
                student_hdr=$STUDENT_ANSWER_FOLDER/$src_file_name.h

                if [ ! -f "$student_src" ] && [[ "$src_file_name" != "completo" ]] ; then
                    echo_e_salva_log " - Arquivo esperado '$student_src' não encontrado!"
                    student_files_missing=$(expr $student_files_missing + 1)
                elif [[ "$src_file_name" != "completo" ]]; then
                    echo_e_salva_log " - Arquivo esperado '$student_src' encontrado!"
                    student_files_found=$(expr $student_files_found + 1)
                fi

                if [ "$HEADER_FILES_EXIST" = "true" ]; then
                    if [ ! -f "$student_hdr" ] && [[ "$src_file_name" != "completo" ]] && [[ "$src_file_name" != "main" ]]; then
                        echo_e_salva_log " - Arquivo esperado '$student_hdr' não encontrado!"
                        student_files_missing=$(expr $student_files_missing + 1)
                    elif [[ "$src_file_name" != "completo" ]] && [[ "$src_file_name" != "main" ]]; then
                        echo_e_salva_log " - Arquivo esperado '$student_hdr' encontrado!"
                        student_files_found=$(expr $student_files_found + 1)
                    fi
                fi
            done
            if [ $student_files_missing -gt 0 ] ; then
                # test_cases_results["arquivos_faltando"]=$student_files_missing
                stats_alunos["$student_name,arquivos_faltando"]=$student_files_missing
                echo_e_salva_log " - Arquivos esperados enviados: Faltando!"
            else
                echo_e_salva_log " - Arquivos esperados enviados: Ok!"
            fi
            stats_alunos["$student_name,arquivos_corretos"]=$student_files_found

            ##########################################
            # Copiando os arquivos
            ##########################################
            echo_e_salva_log "\nCOPIANDO OS ARQUIVOS PARA A PASTA DE RESULTADO DO ALUNO:"

            for src_file_name in "${config_test_names[@]}"; do
                echo_e_salva_log " - Pasta $src_file_name:"
                FILE_NAME_FOLDER=$STUDENT_RESULT_FOLDER/$src_file_name
                echo_e_salva_log "   - Copiando os $DIR_GAB_CASOS de teste para a pasta $FILE_NAME_FOLDER"
                cp -r $DIR_GAB_CASOS $FILE_NAME_FOLDER

                if find "$STUDENT_ANSWER_FOLDER" -maxdepth 1 -type f -name "*.h" | read; then
                    if find "$DIR_GAB_INCLUDES" -maxdepth 1 -type f -name "*.h" | read; then

                        if [[ "$src_file_name" != "completo" ]] ; then
                            echo_e_salva_log "   - Copiando os $DIR_GAB_INCLUDES/*.h do professor para a pasta $FILE_NAME_FOLDER"
                            cp $DIR_GAB_INCLUDES/*.h $FILE_NAME_FOLDER
                            echo_e_salva_log "   - Copiando os $DIR_GAB_INCLUDES/*.o do professor para a pasta $FILE_NAME_FOLDER"

                            cp $DIR_GAB_OBJ/*.o $FILE_NAME_FOLDER
                            echo_e_salva_log "   - Removendo o $src_file_name.o do professor da pasta $FILE_NAME_FOLDER"

                            rm $FILE_NAME_FOLDER/$src_file_name.o
                            echo_e_salva_log "   - Copiando o $STUDENT_ANSWER_FOLDER/$src_file_name.c do aluno para a pasta $FILE_NAME_FOLDER"
                            cp $STUDENT_ANSWER_FOLDER/$src_file_name.c $FILE_NAME_FOLDER
                        else
                            for filepath in "$DIR_GAB_OBJ/"*.o; do
                                if [[ -f "$filepath" ]]; then
                                    filename=$(basename "$filepath" .o)
                                    echo_e_salva_log "   - Copiando os $STUDENT_ANSWER_FOLDER/$filename.c do aluno para a pasta $FILE_NAME_FOLDER"
                                    cp $STUDENT_ANSWER_FOLDER/$filename.c $FILE_NAME_FOLDER
                                    if [[ "$filename" != "main" ]]; then
                                        echo_e_salva_log "   - Copiando os $STUDENT_ANSWER_FOLDER/$filename.h do aluno para a pasta $FILE_NAME_FOLDER"
                                        cp $STUDENT_ANSWER_FOLDER/$filename.h $FILE_NAME_FOLDER
                                    fi
                                fi
                            done
                        fi
                    fi
                fi
            done

            declare -a student_extra_src_files
            aluno_tem_arquivo_completo_c_ou_h=false
            if [[ "$FIXED_INTERFACE" == false ]] ; then
                echo_e_salva_log " - Copiando Arquivos Extras do Aluno:"
                for filepath in "$STUDENT_ANSWER_FOLDER/"*.c; do
                    if [[ -f "$filepath" ]]; then
                        filename=$(basename "$filepath" .c)
                        if [[ "$filename" == "completo" ]]; then
                            aluno_tem_arquivo_completo_c_ou_h=true
                        fi

                        found=false
                        for gab_src_file in "$DIR_GAB_OBJ/"*.o; do
                            gab_src_file=$(basename "$gab_src_file" .o)
                            if [[ "$gab_src_file" = "$filename" ]]; then
                                found=true
                                break
                            fi
                        done
                        if [ "$found" = "false" ]; then
                            for src_file_path in "${config_test_names[@]}"; do
                                if [[ $MAIN_AGRUPADA == false || $src_file_path == "main" || $src_file_path == "completo" ]]; then
                                    echo_e_salva_log "   - Copiando $filepath para $STUDENT_RESULT_FOLDER/$src_file_path"
                                    cp $filepath $STUDENT_RESULT_FOLDER/$src_file_path
                                fi
                            done
                        fi
                    fi
                done

                for filepath in "$STUDENT_ANSWER_FOLDER/"*.h; do
                    if [[ -f "$filepath" ]]; then
                        filename=$(basename "$filepath" .h)
                        if [[ "$filename" == "completo" ]]; then
                            aluno_tem_arquivo_completo_c_ou_h=true
                        fi
                        found=false
                        for gab_src_file in "$DIR_GAB_INCLUDES"/*.h; do
                            gab_src_file=$(basename "$gab_src_file" .h)
                            if [[ "$gab_src_file" = "$filename" ]]; then
                                found=true
                                break
                            fi
                        done
                        if [ "$found" = "false" ]; then
                            for src_file_path in "${config_test_names[@]}"; do
                                if [[ $MAIN_AGRUPADA == false || $src_file_path == "main" || $src_file_path == "completo" ]]; then
                                    echo_e_salva_log "   - Copiando $filepath para $STUDENT_RESULT_FOLDER/$src_file_path"
                                    cp $filepath $STUDENT_RESULT_FOLDER/$src_file_path
                                fi
                            done
                        fi
                    fi
                done

            fi

            if [[ $aluno_tem_arquivo_completo_c_ou_h == true ]]; then
                echo_e_salva_log " - Não é permitido ter arquivos 'completo.c/.h' nesta versão do script! O aluno receberá nota zero por isso. "
                for src_file_dir in "${config_test_names[@]}"; do
                    notas_testes["$student_name,$src_file_dir"]=0
                    stats_alunos["$student_name,$src_file_dir,saidas_certas"]=0
                    stats_alunos["$student_name,$src_file_dir,valgrinds_certos"]=0
                done
                stats_alunos[$student_name,arquivos_corretos]=0
                stats_alunos[$student_name,compilacoes_corretas]=0
                stats_alunos[$student_name,linkagens_corretas]=0
                continue
            fi

            extra_files_array_size=${#student_extra_src_files[@]}
            extra_n_compilation=$((n_folders_to_compile * extra_files_array_size))
            student_n_compilations=$((n_compilations))

            echo_e_salva_log " - Arquivos copiados: ok!"
            echo_e_salva_log "\nCOMPILANDO OS ARQUIVOS NA PASTA DE RESULTADO DO ALUNO:"

            compilation_errors=0
            correct_compilations=0

            cd $STUDENT_RESULT_FOLDER
            for src_file_dir in "${config_test_names[@]}"; do
                echo "   - Compilando a pasta $src_file_dir do aluno, gerando os .o's"
                cd $src_file_dir
                gcc -Wall -c *.c 2>> result_compilation.txt
                if [ $? -ne 0 ]; then
                    echo_e_salva_log "   - Erro de compilação! Verifique os arquivos da pasta $src_file_dir."
                    compilation_errors=$(expr $compilation_errors + 1)
                else
                    echo_e_salva_log "   - Compilação dos arquivos do aluno na pasta $src_file_dir ok!"
                    echo_e_salva_log "   - Arquivo de output gerado: $STUDENT_RESULT_FOLDER/$src_file_dir/result_compilation.txt"
                    correct_compilations=$(expr $correct_compilations + 1)
                fi
                cd ../
            done
            cd ../../

            stats_alunos["$student_name,compilacoes_corretas"]=$correct_compilations

            if [ $compilation_errors -gt 0 ] ; then
                echo_e_salva_log " - Arquivos Compilados: Erro!: $compilation_errors arquivos com erros de compilacao.\n"
            fi
            echo_e_salva_log " - Arquivos Compilados: ok!"

            ##########################################
            # Linkando os arquivos compilados
            ##########################################
            echo_e_salva_log "\nLINKANDO OS ARQUIVOS COMPILADOS:"

            linking_errors=0
            correct_linkings=0
            for src_file_dir in "${config_test_names[@]}"; do
                echo_e_salva_log " - Pasta $src_file_dir:"
                echo_e_salva_log "   - Gerando o binário prog linkando com o(s) arquivo(s) $src_file_dir/*.o"

                gcc -o $STUDENT_RESULT_FOLDER/$src_file_dir/prog $STUDENT_RESULT_FOLDER/$src_file_dir/*.o -lm 2>> $STUDENT_RESULT_FOLDER/$src_file_dir/result_linking.txt
                if [ $? -ne 0 ]; then
                    echo_e_salva_log "   - Arquivos Linkados: Erro! Binário prog não gerado."
                    linking_errors=$(expr $linking_errors + 1)
                else
                    echo_e_salva_log "   - Arquivos Linkados: Ok! Binário prog gerado com sucesso."
                    correct_linkings=$(expr $correct_linkings + 1)
                fi
                echo_e_salva_log "   - Arquivo de output gerado: $STUDENT_RESULT_FOLDER/$src_file_dir/result_linking.txt"
            done
            if [ $linking_errors -gt 0 ] ; then
                echo_e_salva_log " - Arquivos Linkados: Erro! $linking_errors arquivos com erros de linkagem."
            fi
            stats_alunos["$student_name,linkagens_corretas"]=$correct_linkings

            ##################################################
            # Executando o Programa com ou sem Valgrind
            ##################################################
            if [ "$IGNORE_RESULTS" = "false" ] || [ "$IGNORE_VALGRIND" = "false" ]; then
                if [ "$IGNORE_VALGRIND" = "true" ]; then
                    echo_e_salva_log "\nEXECUTANDO O PROGRAMA EM CADA CASO:"
                else
                    echo_e_salva_log "\nEXECUTANDO O VALGRIND EM CADA CASO:"
                fi
                for src_file_dir in "${config_test_names[@]}"; do
                    DIR_CASES=$STUDENT_RESULT_FOLDER/$src_file_dir/Casos
                    n_cases_folders=0
                    n_correct_answers=0
                    n_correct_valgrinds=0
                    sum_of_the_grades_of_all_cases=0.0
                    for DIR_CASE in "$DIR_CASES"/*; do
                        (( n_cases_folders++ ))
                        sum_of_the_grades_of_current_case=0.0
                        txt_out_files=$(find "$DIR_CASE/saida/" -type f -name "*.txt")
                        if [ -n "$txt_out_files" ]; then
                            rm -r $DIR_CASE/saida/*.txt
                        fi
                        case_number=${DIR_CASE##*/}
                        echo_e_salva_log " - Pasta $src_file_dir / Caso $case_number:"

                        outputStdOut="${DIR_CASE}/saida/saida.txt"
                        input_file="${DIR_CASE}/entrada.txt"

                        binary=$STUDENT_RESULT_FOLDER/$src_file_dir/prog
                        valgrind_args="--leak-check=full --log-file=$DIR_CASE/result_valgrind.txt"

                        if [ "$IGNORE_VALGRIND" = "false" ]; then
                            if [ "$REDIRECT_STDOUT" = true ]; then
                                run_output=$(timeout -s 9 $TIMEOUT valgrind $valgrind_args $binary $DIR_CASE < $input_file > $outputStdOut 2>&1)
                            else
                                run_output=$(timeout -s 9 $TIMEOUT valgrind $valgrind_args $binary $DIR_CASE < $input_file > /dev/null 2>&1)
                            fi
                        else
                            if [ "$REDIRECT_STDOUT" = true ]; then
                                run_output=$(timeout -s 9 $TIMEOUT $binary $DIR_CASE < $input_file > $outputStdOut 2>&1)
                            else
                                run_output=$(timeout -s 9 $TIMEOUT $binary $DIR_CASE < $input_file > /dev/null 2>&1)
                            fi
                        fi

                        valgrind_desconto_percent=$(echo "scale=2; $valgrind_desconto * 100.0" | bc)

                        there_is_a_wrong_valgrind=false
                        if [ "$IGNORE_VALGRIND" = "false" ]; then
                            if [[ -f "$DIR_CASE/result_valgrind.txt" ]]; then
                                valgrind_result_file=$DIR_CASE/result_valgrind.txt
                                echo_e_salva_log "   - Arquivo de output gerado: $DIR_CASE/result_valgrind.txt."

                                # Valgring returns
                                allocs=0
                                frees=0
                                errors=0
                                contexts=0

                                # Using while read loop to process each line of the file
                                while IFS= read -r line; do
                                    if echo "$line" | grep -q "total heap usage"; then
                                        # Extract the allocs (position 5) and frees (position 7) numbers on the string
                                        allocs=$(echo "$line" | awk '{print $5}')
                                        frees=$(echo "$line" | awk '{print $7}')
                                    elif echo "$line" | grep -q "ERROR SUMMARY"; then
                                        # Extract the errors (position 4) and contexts (position 7) numbers on the string
                                        errors=$(echo "$line" | awk '{print $4}')
                                        contexts=$(echo "$line" | awk '{print $7}')
                                    fi
                                done < "$valgrind_result_file"

                                if test "$allocs" = "$frees" && test "$errors" = "0"; then
                                    echo_e_salva_log "   - Valgrind: Ok! allocs: $allocs, frees: $frees, errors: $errors | Desconto do valgrind: 0.0%"
                                else
                                    echo_e_salva_log "   - Valgrind: Incorreto! allocs: $allocs, frees: $frees, errors: $errors | Desconto do valgrind $valgrind_desconto_percent%"
                                    there_is_a_wrong_valgrind=true
                                fi
                            else
                                echo_e_salva_log "   - Valgrind: Incorreto! Verifique se o binário prog foi gerado corretamente. Ou se o Valgrind está instalado."
                                there_is_a_wrong_valgrind=true
                            fi
                        fi

                        DIR_CASE_SAIDA=$DIR_CASE/saida
                        txt_file_names=()
                        there_is_a_wrong_answer=false

                        # Percorre todos os arquivos
                        declare -A txts_corretos

                        for key in "${!pesos_arquivos[@]}"; do
                            if [[ "$key" == *".txt" ]]; then
                                txts_corretos["$key"]=0.0
                            fi
                        done

                        if [ "$IGNORE_RESULTS" = "false" ]; then
                            for txt_file in "${config_file_names[@]}"; do
                                gab_case_txt_file="$DIR_GAB_CASOS/$case_number/saida"/$txt_file
                                if [ -f "$gab_case_txt_file" ]; then         # Check if the file is a regular file (not a directory or special file)
                                    filename=$(basename -- "$gab_case_txt_file")   # Get only the file name without the full path
                                    txt_file_names+=("$filename")  # Add the file name to the array
                                    filename_no_ext="${filename%.*}"  # Get only the file name without the extension
                                    student_output_file=$DIR_CASE/saida/$filename

                                    if test -e "$student_output_file"; then
                                        # Making a copy of the professor out.txt file and the student out.txt file, inside the test cases student folder
                                        output_student_copy="$filename_no_ext"_student_copy.txt
                                        output_professor_copy="$filename_no_ext"_professor_copy.txt

                                        cp $DIR_CASE_SAIDA/$filename $DIR_CASE_SAIDA/$output_student_copy
                                        cp $DIR_GAB_CASOS/$case_number/saida/$filename $DIR_CASE_SAIDA/$output_professor_copy

                                        chmod 777 $DIR_CASE_SAIDA/$output_student_copy
                                        chmod 777 $DIR_CASE_SAIDA/$output_professor_copy

                                        # Removing trailing white spaces at end of each line, and removing trailing newlines at the end of the file
                                        sed -i 's/[[:space:]]*$//' "$DIR_CASE_SAIDA/$output_student_copy"
                                        sed -i ':a; /./,$!{N;ba}; /^$/d' "$DIR_CASE_SAIDA/$output_student_copy"
                                        sed -i 's/[[:space:]]*$//' "$DIR_CASE_SAIDA/$output_professor_copy"
                                        sed -i ':a; /./,$!{N;ba}; /^$/d' "$DIR_CASE_SAIDA/$output_professor_copy"

                                        # Open both files for reading
                                        exec 3< "$DIR_CASE_SAIDA/$output_student_copy"
                                        exec 4< "$DIR_CASE_SAIDA/$output_professor_copy"

                                        files_are_equal="true"

                                        while true; do
                                            # Read a line from each file
                                            read -r line1 <&3
                                            read -r line2 <&4

                                            # Check if we reached the end of both files
                                            if [[ -z "$line1" && -z "$line2" ]]; then
                                                break
                                            fi

                                            # Ignore blank lines and continue the loop
                                            if [[ -z "$line1" && -z "$line2" ]]; then
                                                continue
                                            fi

                                            # Compare lines and check for differences
                                            if [[ "$line1" != "$line2" ]]; then
                                                files_are_equal="false"
                                            fi
                                        done

                                        # Close file descriptors
                                        exec 3<&-
                                        exec 4<&-

                                        if test "$files_are_equal" = "false"; then
                                            there_is_a_wrong_answer=true
                                            echo_e_salva_log "   - Resultado para o $filename: Incorreto! Peso: 0.0"
                                        else
                                            txts_corretos[$txt_file]=1.0
                                            echo_e_salva_log "   - Resultado para o $filename: Ok! Peso: ${pesos_arquivos[$txt_file]}"
                                            (( n_correct_answers++ ))
                                        fi

                                        rm "$DIR_CASE_SAIDA/$output_student_copy"
                                        rm "$DIR_CASE_SAIDA/$output_professor_copy"
                                    else
                                        echo_e_salva_log "   - O aluno não gerou o arquivo de saída $DIR_CASE_SAIDA/$filename, considerando resultado incorreto! Peso: 0.0"
                                        there_is_a_wrong_answer=true
                                    fi
                                fi
                            done

                            for txt_file in "${!pesos_arquivos[@]}"; do
                                sum_of_the_grades_of_current_case=$(echo "scale=2; $sum_of_the_grades_of_current_case + ${txts_corretos["$txt_file"]} * ${pesos_arquivos["$txt_file"]}" | bc)
                            done
                        else
                            sum_of_the_grades_of_current_case=$peso_total_arquivos
                        fi

                        if [[ "$there_is_a_wrong_valgrind" = "false" ]]; then
                            (( n_correct_valgrinds++ ))
                            multiplicador=1.0
                        else
                            multiplicador=$(echo "scale=2; 1.0 - $valgrind_desconto" | bc)
                        fi
                        desconto_valgrind_atual=$(echo "scale=2; 100*(1.0 - $multiplicador)" | bc)
                        sum_of_the_grades_of_current_case_minus_valgrind=$(echo "scale=2; $sum_of_the_grades_of_current_case * $multiplicador" | bc)
                        echo_e_salva_log "   - Nota para o Caso (soma dos pesos): $sum_of_the_grades_of_current_case (soma total) - $desconto_valgrind_atual% (desconto do valgrind) = $sum_of_the_grades_of_current_case_minus_valgrind de $peso_total_arquivos pontos."
                        sum_of_the_grades_of_all_cases=$(echo "scale=2; $sum_of_the_grades_of_all_cases + $sum_of_the_grades_of_current_case_minus_valgrind" | bc)

                    done

                    nota_para_pasta=$(echo "scale=2; $sum_of_the_grades_of_all_cases / ($n_cases_folders * $peso_total_arquivos)" | bc)
                    nota_max_pasta=$(echo "scale=2; $n_cases_folders * $peso_total_arquivos" | bc)
                    nota_perc_para_pasta=$(echo "scale=2; $nota_para_pasta * 100" | bc)


                    notas_testes["$student_name,$src_file_dir"]=$(echo "scale=2; $nota_para_pasta * ${pesos_testes[$src_file_dir]}" | bc)
                    echo_e_salva_log " - Nota para a pasta $src_file_dir (máximo ${pesos_testes[$src_file_dir]}) - $sum_of_the_grades_of_all_cases de $nota_max_pasta - $nota_perc_para_pasta% de ${pesos_testes[$src_file_dir]}: ${notas_testes[$student_name,$src_file_dir]}."

                    #considerando a média das notas de todos os casos ($nota_para_pasta) : $nota_para_pasta * ${pesos[$dictFolder]}/10.0 = $nota_final_para_pasta"
                    echo_e_salva_log " -----"

                    stats_alunos["$student_name,$src_file_dir,saidas_certas"]=$n_correct_answers
                    stats_alunos["$student_name,$src_file_dir,valgrinds_certos"]=$n_correct_valgrinds
                done
            fi

            calcula_nota_final $student_name
            cria_arquivo_resultado_aluno $student_name

        fi
        
    done < <(find "$DIR_RESPOSTAS" -mindepth 1 -type d -print0 | sort -z)
}

if [[ $1 == "--professor" ]]; then
    RUN_PROFESSOR_SCRIPT=true
fi

le_arq_config

if [[ $RUN_PROFESSOR_SCRIPT == true ]]; then
    executa_professor
else
    executa_aluno
    # calcula_nota_final
    imprime_resultados_e_cria_csv
    salva_json_saida
    # le_saida_script_correcao
fi

