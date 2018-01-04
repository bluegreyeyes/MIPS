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

/*==================================================
 *
 * 			Fonction loadCurrentInstruction
 *
 * 	Goal:
 * 	Load in the Instruction Register the instruction
 * 	pointed by the Program Counter.
 *
 *==================================================
 */
void loadCurrentInstruction();

/*==================================================
 *
 * 			Fonction idInstr
 *
 * 	Goal:
 * 	Returns the opcode, using the instr enumeration,
 * 	of the instruction loaded in the Instruction
 * 	Register.
 *
 *==================================================
 */
instr idInstr();

/*==================================================
 *
 * 			Fonction readOperands
 *
 * 	Goal:
 * 	Fills the provided Operands structure with
 * 	the operands found in the instruction loaded
 * 	in the Instruction Register.
 *
 * 	Interface :
 * 	- operands : A pointer to the Operands struct.
 * 	to be filled.
 *
 *==================================================
 */
void readOperands(Operands *operands);

/*==================================================
 *
 * 			Fonction updateProgramCounter
 *
 * 	Goal:
 * 	Adds 4 to the content of the Program Counter
 *
 *==================================================
 */
void updateProgramCounter();

#endif
