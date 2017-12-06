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

typedef enum instr {ADD, ADDI, AND, BEQ, BGTZ, BLEZ, BNE, DIV, J, JAL, JR, LUI, LW, MFHI, MFLO, MULT, NOP, OR, ROTR, SLL, SLT, SRL, SUB, SW, SYSCALL, XOR} instr;

/* Prototypes */

/* Identifie une instruction : Renvoie la valeur de l'énum. correspondant */
instr idInstr(char* instr);

/* Ajoute à l'instruction une trame fournie (un champ) */
/* FAIT + VERIF */
void addTrame(int trameBin[], int index, int trame[], int trame_lengh);

/* Initialise une trame binaire à 0 */
/* FAIT + VERIF */
void initTrame(int trameBin[], int length);

/* Transforme une chaîne de caractères représentant un nombre décimal en nombre décimal */
/* FAIT + VERIF */
int strToDec(char number[]);

/* Renvoie la valeur décimale correspondante à la trame binaire fournie */
/* FAIT + VERIF */
int binToDec(int bin_word[], int len);

/* Renvoie le caractère hexa correspondant au tableau de 4 bits passé en param. */
/* FAIT + VERIF */
char binToHexa(int bin_halfword[]);

/* Tansforme une chaîne de carac. représentant un nombre hexa en nombre décimal */
/* FAIT + VERIF */
int strHexaToDec(char hexa_number[]);

/* Traduit une trame binaire en hexadécimal */
/* FAIT + VERIF */
void translateBinTrameToHexa(int trameBin[], char trameHexa[]);

#endif