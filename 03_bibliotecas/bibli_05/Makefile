all: main teste correcao

main: main.c string_utils.c
	gcc -o main string_utils.c main.c

teste: teste.c string_utils.c
	gcc -o teste string_utils.c teste.c
	./teste
	rm -f teste

clean:
	rm -f main teste