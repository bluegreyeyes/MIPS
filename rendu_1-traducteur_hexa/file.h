#ifndef __FILE_H__
#define __FILE_H__

/* Ecrit les datas dans le fichier fourni */
void writeInFile(FILE* file, char data[]);

/* Récupère un numéro de registre */
/* FAIT + VERIF */
int readRegister(FILE* file);

/* Récupère une valeur immédiate ou un offset */
/* FAIT + VERIF */
int readImmValue(FILE* file);

/* Récupère une adresse */
int readAddress(FILE* file);

/* Ouvre un fichier avec le mode choisi */
/* FAIT + VERIF */
FILE* openFile(char* filename, char* mode);

/* Ferme le fichier fourni */
/* FAIT + VERIF */
void closeFile(FILE* file);

/* Récupère l'op_code en tête d'instruction */
/* FAIT + VERIF */
void readInstr(FILE* file, char* instr);

#endif
