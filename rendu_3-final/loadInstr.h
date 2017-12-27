/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Load Instructions Module: manage to move the code into memory.
 *    - Interaction with the file in hexadecimal.
 *    - Communication with memory
 *
 * =================================================
 */

#ifndef __LOADINSTR_H__
#define __LOADINSTR_H__

/* Ouvre un fichier avec le mode choisi */
FILE* openFile(char* filename, char* mode);

/* Ferme le fichier fourni */
void closeFile(char* filename, FILE* file);

/*Charge les intructions contenues dans instructions_file dans la mémoire*/
void loadInstructionsInMemory (char* filename);

/* Lit une instruction depuis le fichier instruction_file et la place dans la chaîne instruction */
void readInstructionFromFile (FILE * instruction_file, char instruction[]);

/* Tansforme une chaîne de carac. représentant un nombre hexa en nombre décimal */
int strHexaToDec(char hexa_number[]);

#endif
