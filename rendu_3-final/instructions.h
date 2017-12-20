/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Instructions Module : manage to move the code into memory.
 *    - Interaction with the file in hexadecimal.
 *    - Communication with memory
 *
 * =================================================
 */

#ifndef __INSTRUCTIONS_H__
#define __INSTRUCTIONS_H__

/* Identifie une instruction d'après son opcode */
instr idInstr (int bin_trame[]);

/* Remplie la structure operand avec les opérandes identifiés lors du décodage de l'instruction */
void readOperandes (int bin_trame[], operand * operands);

#endif
