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


/*==================================================
 *
 * 			Function readTextMemory
 *
 * 	Goal:
 * 	Reads program's datas contain in the memory.
 *
 *
 *==================================================
 */

int readTextMemory (int address);


/*==================================================
 *
 * 			Function writeTextMemory
 *
 * 	Goal:
 * 	Write program's datas in the memory.
 *
 *
 *==================================================
 */

void writeTextMemory (int address, int value);


/*==================================================
 *
 * 			Function readDataMemory
 *
 * 	Goal:
 * 	Reads datas (not program's data) contain in the memory.
 *
 *
 *==================================================
 */
int readDataMemory (int address);


/*==================================================
 *
 * 			Function writeDataMemory
 *
 * 	Goal:
 * 	Write datas in the memory.
 *
 *
 *==================================================
 */
void writeDataMemory (int address, int value);

#endif
