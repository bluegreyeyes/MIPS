
#include <stdio.h>
#include <stdlib.h>


#include "constantes.h"
#include "memory.h"
#include "register.h"
#include "trad.h"
#include "file.h"
#include "loadInstr.h"


void loadInstructionsInMemory (char* filename){

	/* Variables */

	FILE* instrFile = NULL;
	char instruction[INSTR_LEN];
	int offset = 0;

	/* Code */

	instrFile = openFile(filename, "r");

	do
	{
		/* Retrieving an hexadecimal instruction */
		readInstructionFromFile(instrFile, instruction);

		/* Checking if we haven't reach the end of the file */
		if(instruction[0] == '\0')
			break;

		/* Tranlate the instruction in decimal and write it in the memory */
		writeTextMemory(offset, strHexaToDec(instruction));

		/* Moving to the next free space */
		offset++;

	}while(1);

	/* Writting a EXIT instruction to ensure system stop */
	writeTextMemory(offset, EXIT_INSTR);

	closeFile(filename, instrFile);
}



void readInstructionFromFile (FILE * instruction_file, char instruction[]){

	/* Variables */

	char c;
	int i = 0;

	/* Code */

	do
	{
		c = fgetc(instruction_file);
		instruction[i] = c;
		i++;

	}while(i < INSTR_LEN && !feof(instruction_file) && c != '\n');

	/* Adding a null terminator at the end of the string */
	instruction[INSTR_LEN-1] = '\0';

	/* Putting a null terminator in first position if the end of the file is detected */
	if(feof(instruction_file))
		instruction[0] = '\0';
}



char *translateInstructionFileToHexa(char *filename){
	 
	/* Variables */
	int bin_trame[TRAME_BIN_LEN] = {0},
	    i = 0;

	int opcode_ok = 0;

	char hexa_trame[TRAME_HEXA_LEN] = "",
	     instr[INSTR_MAX_LEN] = "",
	     *hexa_file_name = NULL;

	FILE *input_file = NULL,
	     *hexa_file = NULL;

	/* Creating name of the new hexa file */
	hexa_file_name = (char *) malloc((FILENAME_LEN + 4) * sizeof(char));
	createHexaFilename(filename, hexa_file_name);

	/* Opening the needed files to proceed */
	input_file = openFile(filename, "r");
	hexa_file = openFile(hexa_file_name, "w");

	/* Code */

	do
	{
		readInstr(input_file, instr);

		/* We have reached the end of the file, exiting the loop */
		if(instr[0] == '\0')
			break;

		/* Reading a blank line, we go to the next reading cycle */
		if(instr[0] == '\n')
			continue;

		if(instr[0] == '#'){
			nextLine(input_file);
			continue;
		}

		/* Init. of the trame and opcode flag */
		initTrame(bin_trame, 32);
		opcode_ok = 0;

		/* Identifying the instruction and retrieving the operands */
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

				/* Retriveing registers */
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

				/* Retrieving registers */
				addRegCode(input_file, bin_trame, 11);
				addRegCode(input_file, bin_trame, 6);

				/* Retrieving imm value */
				addImmValueCode(input_file, bin_trame, 16);
				break;

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


				/* Retrieving registers */
				addRegCode(input_file, bin_trame, 6);
				addRegCode(input_file, bin_trame, 11);

				/* Retrieving imm value */
				addImmValueCode(input_file, bin_trame, 16);

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

				break;

			default:
				printf("Instruction non prise en charge.\n");
				break;

		}

		/* Translating binary trame to hexadecimal trame */
		translateBinTrameToHexa(bin_trame, hexa_trame);

		/* Writing hexa trame in the new file */
		writeInFile(hexa_file, hexa_trame);

		/* Testing the presence of a comment at the end of the line */
		if(testComment(input_file))
			nextLine(input_file);

	}while(1);

	/* Safely closing the files before the end of the program */
	closeFile(filename, input_file);
	closeFile(hexa_file_name, hexa_file);

	return(hexa_file_name);
}


char *readSingleInstruction(FILE *input_stream){
	 
	/* Variables */
	int bin_trame[TRAME_BIN_LEN] = {0},
	    i = 0;

	int opcode_ok = 0;

	char* hexa_trame = NULL;
	char instr[INSTR_MAX_LEN] = "";

	/* Code */

	hexa_trame = (char *) malloc(TRAME_HEXA_LEN * sizeof(char));

		readInstr(input_stream, instr);

//		/* We have reached the end of the file, exiting the loop */
//		if(instr[0] == '\0')
//			break;
//
//		/* Reading a blank line, we go to the next reading cycle */
//		if(instr[0] == '\n')
//			continue;
//
//		if(instr[0] == '#'){
//			nextLine(input_stream);
//			continue;
//		}

		/* Init. of the trame and opcode flag */
		initTrame(bin_trame, 32);
		opcode_ok = 0;

		/* Identifying the instruction and retrieving the operands */
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

				/* Retriveing registers */
				addRegCode(input_stream, bin_trame, 16);
				addRegCode(input_stream, bin_trame, 6);
				addRegCode(input_stream, bin_trame, 11);

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
				addRegCode(input_stream, bin_trame, 16);
				addRegCode(input_stream, bin_trame, 11);
				addRegCode(input_stream, bin_trame, 21);

				break;



			case ADDI:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 1, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

				/* Retrieving registers */
				addRegCode(input_stream, bin_trame, 11);
				addRegCode(input_stream, bin_trame, 6);

				/* Retrieving imm value */
				addImmValueCode(input_stream, bin_trame, 16);
				break;

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


				/* Retrieving registers */
				addRegCode(input_stream, bin_trame, 6);
				addRegCode(input_stream, bin_trame, 11);

				/* Retrieving imm value */
				addImmValueCode(input_stream, bin_trame, 16);

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
				addRegCode(input_stream, bin_trame, 6);

				/* Retrieving offset */
				addImmValueCode(input_stream, bin_trame, 16);

				break;



			case LUI:

				if(!opcode_ok){
					addTrame(bin_trame, 0, (int []){0, 0, 1, 1, 1, 1}, 6);
					opcode_ok = 1;
				}


				/* Retrieving register */
				addRegCode(input_stream, bin_trame, 11);

				/* Retrieving offset */
				addImmValueCode(input_stream, bin_trame, 16);

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
				addRegCode(input_stream, bin_trame, 6);
				addRegCode(input_stream, bin_trame, 11);

				break;



			case JR:

				if(!opcode_ok){
					addTrame(bin_trame, 26, (int []){0, 0, 1, 0, 0, 0}, 6);
					opcode_ok = 1;
				}

				/* Retrieving register */
				addRegCode(input_stream, bin_trame, 6);

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
				addRegCode(input_stream, bin_trame, 16);

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
				addAddressCode(input_stream, bin_trame, 6);

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
				addRegCode(input_stream, bin_trame, 11);

				/* Retrieving offset */
				addImmValueCode(input_stream, bin_trame, 16);

				/* Retrieving register */
				addRegCode(input_stream, bin_trame, 6);

				break;



			case SYSCALL:

				addTrame(bin_trame, 26, (int []){0, 0, 1, 1, 0, 0}, 6);

				break;



			case NOP:

				break;

			case EXIT:

				addTrame(bin_trame, 0, (int []){1,1}, 2);

				break;

			default:
				printf("Instruction non prise en charge.\n");
				break;

		}

		/* Translating binary trame to hexadecimal trame */
		translateBinTrameToHexa(bin_trame, hexa_trame);


	return(hexa_trame);
}



void cleanBuffer(FILE *file){

	while(!feof(file)){ fgetc(file); }
}
