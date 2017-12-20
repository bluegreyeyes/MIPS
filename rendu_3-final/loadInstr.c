
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



void loadInstructionsInMemory (FILE * Instructions_file){

}



void readInstructionsFromFile (FILE * instruction_file, char instruction[]){

}



int strHexaToDec(char hexa_number[]){

}

