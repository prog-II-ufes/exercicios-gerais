all: run teste

run: main.c conta.c usuario.c
	gcc main.c conta.c usuario.c -o main
	./main

teste: teste.c conta.c usuario.c
	rm -rf teste
	gcc teste.c conta.c usuario.c -o teste
	./teste

clean:
	rm -rf main teste