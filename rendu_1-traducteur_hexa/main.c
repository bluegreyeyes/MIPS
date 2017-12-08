
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
	    i = 0;

	int opcode_ok = 0,
	    blank_line = 0;

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
		blank_line = 0;
		readInstr(input_file, instr);

		/* We have reached the end of the file, exiting the loop */
		if(instr[0] == '\0')
			break;

		if(instr[0] == '\n'){
			printf("Ligne blanche\n");
			blank_line = 1;
		}

		/* Initialisation de la trame et du flag d'opcode */
		initTrame(bin_trame, 32);
		opcode_ok = 0;

		/* Identification de l'instruction et récupération des opérandes */
		if(!blank_line){
		switch(idInstr(instr)){

			case ADD:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 0, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

			case SUB:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 0, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

			case AND:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 0, 1, 0, 0}, 6);
					opcode_ok = 1;
				}

			case OR:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 0, 1, 0, 1}, 6);
					opcode_ok = 1;
				}

			case XOR:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 0, 1, 1, 0}, 6);
					opcode_ok = 1;
				}

			case SLT:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){1, 0, 1, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

				/* Lecture des registres */
				addRegCode(input_file, bin_trame, 16);
				addRegCode(input_file, bin_trame, 6);
				addRegCode(input_file, bin_trame, 11);

				break;



			case ROTR:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 0, 0, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

				/* Adding a bit */
				addTrame(bin_trame, 10, (int []){1}, 1);

			case SRL:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 0, 0, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

			case SLL:

				/* Reading registers */
				addRegCode(input_file, bin_trame, 16);
				addRegCode(input_file, bin_trame, 11);
				addRegCode(input_file, bin_trame, 21);

				break;



			case ADDI:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 1, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

			case BEQ:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 0, 0}, 6);
					opcode_ok = 1;
				}

			case BNE:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 0, 1}, 6);
					opcode_ok = 1;
				}


				/* Lecture des registres */
				addRegCode(input_file, bin_trame, 6);
				addRegCode(input_file, bin_trame, 11);

				/* Lecture de la valeur imm */
				addImmValueCode(input_file, bin_trame, 16);

				afficherTrame(bin_trame);

				break;



			case BGTZ:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 1, 1}, 6);
					opcode_ok = 1;
				}

			case BLEZ:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 1, 1, 0}, 6);
					opcode_ok = 1;
				}


				/* Retrieving register */
				addRegCode(input_file, bin_trame, 6);

				/* Retrieving offset */
				addImmValueCode(input_file, bin_trame, 16);

				break;



			case LUI:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 1, 1, 1, 1}, 6);
					opcode_ok = 1;
				}


				/* Retrieving register */
				addRegCode(input_file, bin_trame, 11);

				/* Retrieving offset */
				addImmValueCode(input_file, bin_trame, 16);

				break;



			case DIV:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 1, 1, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

			case MULT:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 1, 1, 0, 0, 0}, 6);
					opcode_ok = 1;
				}


				/* Retrieving registers */
				addRegCode(input_file, bin_trame, 6);
				addRegCode(input_file, bin_trame, 11);

				break;



			case JR:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 0, 1, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

				/* Retrieving register */
				addRegCode(input_file, bin_trame, 6);

				break;



			case MFHI:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 1, 0, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

			case MFLO:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 1, 0, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

				/* Retrieving register */
				addRegCode(input_file, bin_trame, 16);

				break;



			case J:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 0, 1, 0}, 6);
					opcode_ok = 1;
				}

			case JAL:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 0, 0, 1, 1}, 6);
					opcode_ok = 1;
				}


				/* Retrieving address */
				addAddressCode(input_file, bin_trame, 6);

				break;



			case LW:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){1, 0, 0, 0, 1, 1}, 6);
					opcode_ok = 1;
				}

			case SW:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){1, 0, 1, 0, 1, 1}, 6);
					opcode_ok = 1;
				}

				/* Retrieving register */
				addRegCode(input_file, bin_trame, 11);

				/* Retrieving offset */
				addImmValueCode(input_file, bin_trame, 16);

				/* Retrieving register */
				addRegCode(input_file, bin_trame, 6);

				break;



			case SYSCALL:

				addTrame(bin_trame, 26, (int []){0, 0, 1, 1, 0, 0}, 6);

				break;



			case NOP:

				afficherTrame(bin_trame);

				break;

			default:
				printf("Instruction non prise en charge.\n");
				break;

		}

		/* Translating binary trame to hexadecimal trame */
		translateBinTrameToHexa(bin_trame, hexa_trame);

		/* Writing hexa trame in the new file */
		writeInFile(hexa_file, hexa_trame);
		}

	}while(1);

	/* Safely closing the files before the end of the program */
	closeFile(argv[1], input_file);
	closeFile(argv[2], hexa_file);

	return(0);
}
