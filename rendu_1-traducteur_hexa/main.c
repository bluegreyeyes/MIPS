
/*==================================================
 *
 * Projet MIPS - Instructions to Hexadecimal Translator
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Desc : 
 * 	Take as an input the name of a file containing
 * 	a serie of MIPS instructions (one per line) and
 * 	create a file containing all these instructions
 * 	translated in hexadecimal.
 *
 * =================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "trad.h"
#include "file.h"

int main(int argc, char* argv[]){
	 
	/* Variables */
	int bin_trame[TRAME_BIN_LEN] = {0},
	    fill_trame[TRAME_BIN_LEN] = {0},
	    reg = 0,
	    imm_value = 0;

	char hexa_trame[TRAME_HEXA_LEN] = "",
	     instr[INSTR_MAX_LEN] = "";

	FILE *input_file = NULL,
	     *hexa_file = NULL;

	/* Initialisation */
	initTrame(fill_trame);

	/* Check if enough arguments are provided */
	if(argc < 3){
		printf("Please enter the name of the file to convert and the name of the hexa file to be created.\n");
		exit(-1);
	}

	/* TODO : Fonction de sécurisation du nom du fichier */

	/* Opening the needed files to proceed */
	input_file = openFile(argv[1], "r");
	hexa_file = openFile(argv[2], "w");

	/* Code */

	do
	{

		readInstr(input_file, instr);

		/* We have reached the end of the file, exiting the loop */
		if(instr[0] == '\0')
			break;

		initTrame(bin_trame);

		switch(ifInstr(instr)){

		}

		/* Translating binary trame to hexadecimal trame */
		translateBinTrameToHexa(bin_trame, hexa_trame);

		/* Writing hexa trame in the new file */
		writeInFile(hexa_file, hexa_trame);

	}while(1);

	/* Safely closing the files before the end of the program */
	closeFile(argv[1], input_file);
	closeFile(argv[2], hexa_file);

	return(0);
}
