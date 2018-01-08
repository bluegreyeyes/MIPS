#Compilateur à utiliser
CC = gcc

#Nom de l'exécutable
BIN = emul_mips

#Objets nécessaires à la construction de l'exécutable
OBJECTS = *.o

#Arguments à passer au compilateur
CFLAGS =

all: main.o alu.o loadInstr.o instructions.o memory.o register.o file.o trad.o
	$(CC) $(OBJECTS) -o $(BIN)

main.o: main.c *.h
	$(CC) -c -g main.c

alu.o: alu.c *.h
	$(CC) -c -g alu.c

loadInstr.o: loadInstr.c *.h
	$(CC) -c -g loadInstr.c

instructions.o: instructions.c *.h
	$(CC) -c -g instructions.c

register.o: register.c *.h
	$(CC) -c -g register.c

memory.o: memory.c *.h
	$(CC) -c -g memory.c

trad.o: trad.c *.h
	$(CC) -c -g trad.c

file.o: file.c *h
	$(CC) -c -g file.c
