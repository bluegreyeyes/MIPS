/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Module Registers: manage all discussions with registers.
 *    in particular the display of register's state.
 *
 * =================================================
 */

#ifndef __REGISTERS_H__
#define __REGISTERS_H__


/*==================================================
 *
 * 			Function readMIPSRegister
 *
 * 	Goal:
 * 	Reads data contains in register, in order to show the stats
 *  and realize instructions.
 *
 *
 *==================================================
 */
int readMIPSRegister (int reg_number);


/*==================================================
 *
 * 			Function writeRegister
 *
 * 	Goal:
 * 	Write data in register result of an executed instruction.
 *
 *
 *==================================================
 */

void writeRegister (int reg_number, int value);


/*==================================================
 *
 * 			Function initializingRegisters
 *
 * 	Goal:
 * 	Initialize some specials registers :
 *    - zero is a register always equal to 0
 *    - Program Counter is a register contains the address of
 *       the next instruction, so at the beginnnig, it has to contain
 *       the address of the first instruction.
 *
 *
 *==================================================
 */
void initializingRegisters();

#endif
