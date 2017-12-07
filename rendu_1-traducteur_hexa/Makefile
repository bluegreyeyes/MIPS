#Compilateur à utiliser
CC = gcc

#Nom de l'exécutable
BIN = trad_code_mips_to_hexa

#Objets nécessaires à la construction de l'exécutable
OBJECTS = *.o

#Arguments à passer au compilateur
CFLAGS =

all: main.o trad.o file.o
	$(CC) $(OBJECTS) -o $(BIN)

main.o: main.c *.h
	$(CC) -c main.c

trad.o: trad.c *.h
	$(CC) -c trad.c

file.o: file.c *.h
	$(CC) -c file.c
