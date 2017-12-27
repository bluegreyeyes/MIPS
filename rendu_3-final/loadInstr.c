
#include <stdio.h>
#include <stdlib.h>


#include "constantes.h"
#include "loadInstr.h"



FILE* openFile(char* filename, char* mode){

	FILE * fdin = fopen(filename, mode);

	if ( NULL == fdin )
	{
		fprintf(stderr, "Error opening file %s\n", filename);
		perror("");
		exit (EXIT_FAILURE);
	}

	return fdin;
}



void closeFile(char* filename, FILE* file){

	if (fclose(file) == EOF)
	{
		fprintf(stderr, "Error closing file %s\n", filename);
		perror("");
		exit(EXIT_FAILURE);
	}
}



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
		writeMemory(TEXT_MEMORY_START_ADDR + offset, strHexaToDec(instruction));

		/* Moving to the next free space */
		offset++;

	}while(1);

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

	}while(!feof(instruction_file) && c != '\n');

	/* Adding a null terminator at the end of the string */
	instruction[i-1] = '\0';

	/* Putting a null terminator in first position if the end of the file is detected */
	if(feof(instruction_file))
		instruction[0] = '\0';
}



int strHexaToDec(char hexa_number[]){

	/* Variables */

	int hexa_num = 0,
	    pow = 1,
	    len = 0,
	    i;

	/* Code */

	while(hexa_number[len++] != '\0');

	for(i = len-2 ; i > -1 ; i--){

		/* If it's a digit, we compare it to the 0 ref. */
		if(hexa_number[i] >= '0' && hexa_number[i] <= '9'){

			hexa_num += (hexa_number[i] - '0') * pow;
		}
		/* If it's a letter, the ref. is 'a', we then add 1 and multiplie by 10 to obtain the correct value */
		else{

			hexa_num += (hexa_number[i] - 'a' + 10) * pow;
		}

		pow *= 16;
	}

	return(hexa_num);
}

