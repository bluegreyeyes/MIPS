/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Load Instructions Module: manage to move the code into memory.
 *    - Interaction with the file in hexadecimal.
 *    - Communication with memory
 *
 * =================================================
 */

#ifndef __LOADINSTR_H__
#define __LOADINSTR_H__

/*==================================================
 *
 * 			Function openFile
 *
 * 	Goal:
 * 	Open the selected file in the given mode and
 * 	return it.
 *
 * 	Interface :
 * 	- filename : String containing the relative
 * 	or absolute path to the file to open.
 * 	- mode : The mode in which the file shall be
 * 	open.
 *
 *==================================================
 */
//FILE* openFile(char* filename, char* mode);

/*==================================================
 *
 * 			Function closeFile
 *
 * 	Goal:
 * 	Properly closing the given file.
 *
 * 	Interface :
 * 	- filename : The name of the file to close
 * 	(for debug purpose).
 * 	- file : The FILE pointer to close.
 *
 *==================================================
 */
//void closeFile(char* filename, FILE* file);

/*==================================================
 *
 * 			Function strHexaToDec
 *
 * 	Goal:
 * 	Converting an string representing a hexadecimal
 * 	number into a base 10 integer.
 *	The string shall contains only the hexadecimal
 *	number. The "0x" indicator is not supported.
 *
 * 	Interface :
 * 	- hexa_number : The string to convert into
 * 	an integer
 *
 *==================================================
 */
//int strHexaToDec(char hexa_number[]);

/*==================================================
 *
 * 			Function readInstructionFromFile
 *
 * 	Goal:
 * 	Reads a single line in the formated file given
 * 	and places it in the instruction string.
 * 	It is supposed that the instructions recovered
 * 	are maximum 8 characters long.  
 * 	Will return a '\0' in the instruction's first
 * 	character if an EOF is detected.
 *
 * 	Interface :
 * 	- instruction_file : The file from which the
 * 	instructions are red.
 * 	- instruction : The string which contains the
 * 	recovered instruction at the end of the function.
 *
 *==================================================
 */
void readInstructionFromFile (FILE * instruction_file, char instruction[]);

/*==================================================
 *
 * 			Function loadInstructionsInMemory
 *
 * 	Goal:
 * 	Reads a formated instruction file and puts
 * 	its content in the text memory of the processor.
 *
 * 	Interface :
 * 	- filename : A string containing the absolute
 * 	or relative path to the file to read.
 *
 *==================================================
 */
void loadInstructionsInMemory (char* filename);


/* Traduction du fichier fourni en hexa */
char *translateInstructionFileToHexa(char *filename);

char *readSingleInstruction(FILE *input_stream);

void cleanBuffer(FILE *file);

#endif
