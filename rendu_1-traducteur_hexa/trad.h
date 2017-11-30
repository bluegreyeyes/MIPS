#ifndef __TRAD_H__
#define __TRAD_H__

/* Constantes */

/* Taille d'une trame d'instruction binaire */
#define TRAME_BIN_LEN 32

/* Taille max d'une instruction assembleur MIPS */
#define INSTR_MAX_LEN 5

/* Taille d'une trame d'instruction hexadécimale */
#define TRAME_HEXA_LEN 9

/* Structures */

typedef enum instr {/* TODO : Taper la liste des instr */} instr;

/* Prototypes */

/* Identifie une instruction : Renvoie la valeur de l'énum. correspondant */
instr idInstr(char* instr);

/* Ajoute à l'instruction une trame fournie (un champ) */
void addTrame(int instr_code[], int index, int trame[], int trame_lengh);

/* Traduit une trame binaire en hexadécimal */
void translateBinToHexa(int trameBin[], char trameHexa[]);

/* Initialise une trame binaire à 0 */
void initTrame(int trameBin[]);

/* Transforme une chaîne de caractères représentant un nombre en nombre */
/* FAIT + VERIF */
int strToDec(char number[]);

#endif
