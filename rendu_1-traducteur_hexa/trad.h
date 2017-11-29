#ifndef __TRAD_H__
#define __TRAD_H__

/* Structures */

typedef enum instr {/* TODO : Taper la liste des instr */} instr;

/* Prototypes */

FILE* openFile(char* filename, char* mode);

void closeFile(FILE* file);

/* Récupère l'op_code en tête d'instruction */
void readInstr(FILE* file, char* instr);

/* Identifie une instruction : Renvoie la valeur de l'énum. correspondant */
instr idInstr(char* instr);

/* Récupère un numéro de registre */
int readRegister(FILE* file);

/* Récupère une valeur immédiate ou un offset */
int readImmValue(FILE* file);

/* Récupère une adresse */
int readAddress(FILE* file);

void addTrame(int instr_code[], int index, int trame[], int trame_lengh);

#endif
