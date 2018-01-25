/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * UI : Regroups the fonctions interacting with the
 * user.
 *
 * =================================================
 */

#ifndef __UI_H__
#define __UI_H__



/*==================================================
 *
 * 			Function checkStepMode
 *
 * 	Goal:
 *
 *
 *
 *==================================================
 */
int checkStepMode(char arg[]);


/*==================================================
 *
 * 			Function waitUserGo
 *
 * 	Goal:
 *
 *
 *
 *==================================================
 */
void waitUserGo();


/*==================================================
 *
 * 			Function displayProgram
 *
 * 	Goal:
 *
 *
 *
 *==================================================
 */
void displayProgram(int displayCurrentPos);


/*==================================================
 *
 * 			Function printRegister
 *
 * 	Goal:
 * 	Shows the status of all of registers
 *
 *
 *==================================================
 */
void printRegister();


void displayMemoryState();

#endif
