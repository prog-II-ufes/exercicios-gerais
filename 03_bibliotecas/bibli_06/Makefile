all: main teste

main: main.c temperature_conversor.c
	gcc -o main main.c temperature_conversor.c

teste: teste.c temperature_conversor.c
	gcc -o teste teste.c temperature_conversor.c
	./teste
	rm -f teste

clean:
	rm -f main teste