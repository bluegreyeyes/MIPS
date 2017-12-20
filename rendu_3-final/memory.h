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

/* lecture des données contenues dans la mémoire */
int readMemory (int address);

/* Ecriture de données dans la mémoire */
void writeMemoy (int address, int value);

/*Affiche la valeur de la pile */
void printStack();

#endif
