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
void add(operands operands);

/* Réalise la soustraction de deux valeurs contenues dans des registres et place le résultat dans un troisième registre */
void sub(operands operands);

/* Réalise un saut à l'adresse spécifée */
void jump(operands operands);

#endif
