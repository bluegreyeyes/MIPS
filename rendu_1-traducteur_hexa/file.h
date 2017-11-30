#ifndef __FILE_H__
#define __FILE_H__

/* Ecrit les datas dans le fichier fourni */
void writeInFile(FILE* file, char data[]);

/* Récupère un numéro de registre */
int readRegister(FILE* file);

/* Récupère une valeur immédiate ou un offset */
int readImmValue(FILE* file);

/* Récupère une adresse */
int readAddress(FILE* file);

/* Ouvre un fichier avec le mode choisi */
FILE* openFile(char* filename, char* mode);

/* Ferme le fichier fourni */
void closeFile(FILE* file);

/* Récupère l'op_code en tête d'instruction */
void readInstr(FILE* file, char* instr);

#endif
