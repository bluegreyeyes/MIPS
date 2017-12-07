
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
	    opcode_trame[TRAME_OPCODE_LEN] = {0},
	    reg_trame[TRAME_REG_LEN] = {0},
	    imm_val_trame[TRAME_IMM_LEN] = {0},
	    reg = 0,
	    imm_value = 0,
	    i = 0;

	char hexa_trame[TRAME_HEXA_LEN] = "",
	     instr[INSTR_MAX_LEN] = "";

	FILE *input_file = NULL,
	     *hexa_file = NULL;

	/* Initialisation */
	initTrame(fill_trame, 32);

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

		initTrame(bin_trame, 32);

		switch(ifInstr(instr)){

			case ADD:

				/* Adding the instruction code */
				addTrame(bin_trame, 25, {1, 0, 0, 0, 0, 0}, 6);

			case AND:

				/* Adding the instruction code */
				addTrame(bin_trame, 25, {1, 0, 0, 1, 0, 0}, 6);

				for(i = 0 ; i < 3 ; i++){

					initTrame(reg_trame, TRAME_REG_LEN);
					reg = readRegister(input_file);

					decToBinTrame(reg, reg_trame, TRAME_REG_LEN);

					addTrame(bin_trame, 6 + i*5, reg_trame, 5);
				}

				break;

			case ADDI:

				/* Adding the instruction code */
				addTrame(bin_trame, 0, {1, 0, 0, 0, 0, 0}, 6);

			case BEQ:

				/* Adding the instruction code */
				addTrame(bin_trame, 0, {0, 0, 0, 1, 0, 0}, 6);

				for(i = 0 ; i < 2 ; i++){

					initTrame(reg_trame, TRAME_REG_LEN);
					reg = readRegister(input_file);

					decToBinTrame(reg, reg_trame, TRAME_REG_LEN);

					addTrame(bin_trame, 6 + 5*i, reg_trame, 5);
				}

				initTrame(imm_val_trame, TRAME_IMM_LEN);
				imm_value = readImmValue(input_file);

				decToBinTrame(imm_value, imm_val_trame, TRAME_REG_LEN);

				addTrame(bin_trame, 15, imm_val_trame, TRAME_REG_LEN);

				break;

			case BGTZ:

				/* Adding the instruction code */
				addTrame(bin_trame, 0, {0, 0, 0, 1, 1, 1}, 6);

				/* Retrieving register */
				initTrame(reg_trame, TRAME_REG_LEN);
				reg = readRegister(input_file);

				decToBinTrame(reg, reg_trame, TRAME_REG_LEN);

				addTrame(bin_trame, 6 + 5*i, reg_trame, 5);

				/* Retrieving offset */
				initTrame(imm_val_trame, TRAME_IMM_LEN);
				imm_value = readImmValue(input_file);

				decToBinTrame(imm_value, imm_val_trame, TRAME_REG_LEN);

				addTrame(bin_trame, 15, imm_val_trame, TRAME_REG_LEN);

				break;

			default:
				printf("Instruction non prise en charge.\n");
				break;

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
