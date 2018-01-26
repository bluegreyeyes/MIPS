/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * ALU Module : realize instructions
 *    - Communication with register module to access the Operands
 *    - Communication with memory module
 *
 * =================================================
 */

#ifndef __ALU_H__
#define __ALU_H__

/* Réalise l'addition de deux valeurs contenues dans des registres et place le résultat dans un troisième registre */
void add(Operands operands);


void addi(Operands operands);


void and_instr(Operands operands);


void beq(Operands operands);


void bgtz(Operands operands);


void blez(Operands operands);


void bne(Operands operands);


void div_instr(Operands operands);

/* Réalise un saut à l'adresse spécifée */
void jump(Operands operands);



void jr(Operands operands);


void lui(Operands operands);


void load(Operands operands);


void MFHI(Operands operands);


void MFLO(Operands operands);


void Mult(Operands operands);


void nop(Operands operands);


void or_instr(Operands operands);


/* Réalise la soustraction de deux valeurs contenues dans des registres et place le résultat dans un troisième registre */
void sub(Operands operands);

void store(Operands operands);

void xor(Operands operands);

#endif
