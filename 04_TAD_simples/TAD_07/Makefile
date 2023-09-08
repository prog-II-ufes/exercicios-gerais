all: main teste

main: main.c data.c
	gcc main.c data.c -o main

teste: teste.c data.c
	rm -f teste
	gcc teste.c data.c -o teste
	./teste

clean:
	rm -f main teste