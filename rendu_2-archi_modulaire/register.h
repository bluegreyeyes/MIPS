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

/* lecture des données contenues dans le registre */
int readRegister (in reg_number);

/*Ecriture de données dans un registre */
void writeRegister (int reg_number, int value);

/*Affiche la valeur de tous les registres */
void printRegister ();
