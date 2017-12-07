
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
	    imm_val_trame[TRAME_IMM_LEN] = {0},
	    imm_value = 0,
	    i = 0;

	int opcode_ok = 0;

	char hexa_trame[TRAME_HEXA_LEN] = "",
	     instr[INSTR_MAX_LEN] = "";

	FILE *input_file = NULL,
	     *hexa_file = NULL;

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

		/* Initialisation de la trame et du flag d'opcode */
		initTrame(bin_trame, 32);
		opcode_ok = 0;

		/* Identification de l'instruction et récupération des opérandes */
		switch(idInstr(instr)){

			case ADD:

				/* Adding the instruction code */
				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 0, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

			case AND:

				/* Adding the instruction code */
				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 0, 1, 0, 0}, 6);
					opcode_ok = 1;
				}

				/* Lecture des registres */
				addRegCode(input_file, bin_trame, 16);
				addRegCode(input_file, bin_trame, 6);
				addRegCode(input_file, bin_trame, 11);

				break;

			case ADDI:

				/* Adding the instruction code */
				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 1, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

			case BEQ:

				/* Adding the instruction code */
				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 0, 0}, 6);
					opcode_ok = 1;
				}

			case BNE:

				/* Adding the instruction code */
				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 0, 1}, 6);
					opcode_ok = 1;
				}


				/* Lecture des registres */
				addRegCode(input_file, bin_trame, 6);
				addRegCode(input_file, bin_trame, 11);

				/* Lecture de la valeur imm */
				addImmValueCode(input_file, bin_trame, 16);

				break;

			case BGTZ:

				/* Adding the instruction code */
				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 1, 1}, 6);
					opcode_ok = 1;
				}

			case BLEZ:

				/* Adding the instruction code */
				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 1, 0}, 6);
					opcode_ok = 1;
				}


				/* Retrieving register */
				addRegCode(input_file, bin_trame, 6);

				/* Retrieving offset */
				addImmValueCode(input_file, bin_trame, 16);

				break;

			case DIV:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 1, 1, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

				/* Retrieving registers */
				addRegCode(input_file, bin_trame, 6);
				addRegCode(input_file, bin_trame, 11);


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
