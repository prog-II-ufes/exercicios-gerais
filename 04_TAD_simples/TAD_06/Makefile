all: run teste run_input 

run: main.c matrix_utils.c
	gcc main.c matrix_utils.c -o main
	./main

run_input: main.c matrix_utils.c 
	gcc main.c matrix_utils.c -o main
	./main < ../../Casos/1/entrada.txt > saida.txt

teste: teste.c matrix_utils.c
	rm -f teste
	gcc test.c matrix_utils.c -o teste
	./teste

clean:
	rm -f main teste