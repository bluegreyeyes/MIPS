/* Ce fichier contient toutes les fonctions gérant la traduction des instructions */

#ifndef __TRAD_H__
#define __TRAD_H__


/* Constantes */

/* Taille d'un champ adresse */
#define TRAME_ADDRESS_LEN 26

/* Taille d'une trame d'instruction binaire */
#define TRAME_BIN_LEN 32

/* Taille max d'une instruction assembleur MIPS */
#define INSTR_MAX_LEN 8

/* Taille d'une trame d'instruction hexadécimale */
#define TRAME_HEXA_LEN 9

/* Taille de l'opcode en binaire */
#define TRAME_OPCODE_LEN 6

/* Taille d'un champ de registre */
#define TRAME_REG_LEN 5

/* Taille du champ valeur immédiate */
#define TRAME_IMM_LEN 16



/* Structures */

typedef enum instr {ADD, ADDI, AND, BEQ, BGTZ, BLEZ, BNE, DIV, J, JAL, JR, LUI, LW, MFHI, MFLO, MULT, NOP, OR, ROTR, SLL, SLT, SRL, SUB, SW, SYSCALL, XOR} instr;



/* Prototypes */

/* Identifie une instruction : Renvoie la valeur de l'énum. correspondant */
instr idInstr(char* instr);

/* Ajoute à l'instruction une trame fournie (un champ) */
void addTrame(int instr_code[], int index, int trame[], int trame_lengh);

/* Initialise une trame binaire à 0 */
void initTrame(int trameBin[], int length);

/* Transforme une chaîne de caractères représentant un nombre décimal en nombre décimal */
int strToDec(char number[]);

/* Renvoie la valeur décimale correspondante à la trame binaire fournie */
int binToDec(int bin_word[], int len);

/* Renvoie le caractère hexa correspondant au tableau de 4 bits passé en param. */
char binToHexa(int bin_halfword[]);

/* Tansforme une chaîne de carac. représentant un nombre hexa en nombre décimal */
int strHexaToDec(char hexa_number[]);

/* Retourne la trame binaire qui correspond au nombre décimal contenu dans la chaîne reg_number */
void decToBinTrame(int number, int trame[], int trame_len);

/* Traduit une trame binaire en hexadécimal */
void translateBinTrameToHexa(int trameBin[], char trameHexa[]);

/* Ajoute à la trame binaire le code correspondant au registre lu, à l'index fourni */
void addRegCode(FILE* file, int bin_trame[], int index);

/* Même fonction que la précédente, avec une valeur immédiate/offset */
void addImmValueCode(FILE* file, int bin_trame[], int index);

/* Même fonction que la précédente, avec une adresse */
void addAddressCode(FILE* file, int bin_trame[], int index);

#endif
