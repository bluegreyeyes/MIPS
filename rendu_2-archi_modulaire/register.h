/*==================================================
 *
 * Projet MIPS - Instructions to Hexadecimal Translator
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Module Registers: manage all discussion with registers.
 *    in particular the display of register's state.
 *
 * =================================================
 */

int readRegister (in reg_number);

void writeRegister (int reg_number, int value);

void printRegister ();
