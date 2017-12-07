#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "file.h"
#include "trad.h"

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

void writeInFile(FILE *file, char data[]){
	fprintf(file, "%s\n", data);
}


void readInstr(FILE* file, char* instr){

	/* Variables */

	int i = 0;
	char c;

	/* Code */

	/* Retrieving all caracters from the beginning of the line to the first blank encountered */
	do
	{
		c = fgetc(file);
		instr[i] = c;
		i++;

		/* Detect blank lines and reset the instruction's capture */
		if(c == '\n')
			i = 0;

	}while(c != ' ' && !feof(file));

	/* Adding null terminator at the end of the string */
	instr[i-1] = '\0';

	/* Return a null terminator in first position if the reading function hits the end of the file */
	if(feof(file))
		instr[0] = '\0';
}

int readRegister(FILE* file){

	/* Variables */

	char c;
	char reg_number[3];		/* Register number is max 2 digits long + null terminator */

	int i = 0;

	/* Code */

	/* Searching for the beginning of the register number */
	do
	{
		c = fgetc(file);

	}while(c != '$');

	/* Recovering the register number as a string */
	do
	{
		c = fgetc(file);
		reg_number[i] = c;
		i++;

	}while(c != ',' && c != ' ' && c != '\n');

	reg_number[i-1] = '\0';

	/* Returning the register number as an integer */
	return(strToDec(reg_number));
}



int readImmValue(FILE* file){

	/* Variables */

	int i = 0,
	    hexa = 0;			/* Flag checking if the value is in hexadecimal or decimal format */
	char value[6];			/* An immediat value or an offset is max 5 digits long + null terminator */
	char c;

	/* Code */

	/* Searching the beginning of the value */
	do
	{
		c = fgetc(file);
	}while( c < '0' || c > '9');

	value[i++] = c;

	/* Recovering the immediate value as a string */
	do
	{
		c = fgetc(file);

		/* If the value is given in hexadecimal format, detects it and restart the capture of the string */
		if(c == 'x'){
		
			i = -1;
			hexa = 1;
		}
		else{

			value[i] = c;
		}

		i++;

	}while(c != ' ' && c != '\n');

	value[i-1] = '\0';

	if(hexa){
		return(strHexaToDec(value));
	}
	else{
		return(strToDec(value));
	}
}
