mkdir -p ./outmain
gcc ./main.c -o ./main.exe -lm

for i in ./input/*; do 
    ./main.exe < $i > ./outmain/$(basename $i);

    # Adiciona uma linha em branco no final dos arquivos de saída
    if [ "$(tail -c 1 ./output/$(basename $i))" != "" ]; then
        echo "" >> ./output/$(basename $i);
    fi
    if [ "$(tail -c 1 ./outmain/$(basename $i))" != "" ]; then
        echo "" >> ./outmain/$(basename $i);
    fi
done

diff -w ./output ./outmain