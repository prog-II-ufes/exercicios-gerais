all: geraos principal

principal: main.o esfera_utils.o
	gcc main.o esfera_utils.o -o principal

geraos: main.c esfera_utils.c
	gcc -c main.c esfera_utils.c

clean:
	rm -rf *.o main