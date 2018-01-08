/* Ce module regroupe des fonctions d'intéractions avec les fichiers */

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
void closeFile(char* filename, FILE* file);

/* Récupère l'op_code en tête d'instruction */
void readInstr(FILE* file, char* instr);

/* Passe à la ligne suivante */
void nextLine(FILE *file);

/* Test la présence d'un commentaire en fin de ligne */
int testComment(FILE *file);

/* Ajoute le marqueur "_hex" à une chaîne de carac */
void createHexaFilename(char *filename, char *hexa_filename);

#endif
