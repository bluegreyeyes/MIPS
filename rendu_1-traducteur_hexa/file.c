#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "trad.h"

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
	}while(c != ' ');

	/* Adding null terminator at the end of the string */
	instr[i-1] = '\0';
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
