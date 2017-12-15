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

int readRegister (in reg_number);

void writeRegister (int reg_number, int value);

void printRegister ();
