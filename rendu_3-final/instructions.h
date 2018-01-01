/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Instructions Module : Moves instructions from memory
 * to the instruction register and decode them.
 *    - Communication with text memory and registers
 *
 * =================================================
 */

#ifndef __INSTRUCTIONS_H__
#define __INSTRUCTIONS_H__

/* Charge dans le registre d'instruction l'instruction pointée par le Program Counter */
void loadCurrentInstruction();

/* Identifie une instruction d'après son opcode */
instr idInstr (int bin_trame[]);

/* Remplie la structure operand avec les opérandes identifiés lors du décodage de l'instruction */
void readOperands (int bin_trame[], operand * operands);

#endif
