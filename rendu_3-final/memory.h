/*==================================================
 *
 *                 - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Memory Module : manage all discussions with memory.
 *
 * =================================================
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

/* lecture des données contenues dans la mémoire concernant la partie contenant le programme */
int readTextMemory (int address);

/* Ecriture du programme dans la mémoire */
void writeTextMemory (int address, int value);

/* lecture des données contenues dans la mémoire */
int readDataMemory (int address);

/* Ecriture des données dans la mémoire */
void writeDataMemory (int address, int value);

/*Affiche la valeur de la pile */
void printStack();

#endif
