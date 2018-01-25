#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"
#include "trad.h"
#include "file.h"


int strToDec(char number[]){

	/* Variables */

	int len = 0,
	    dec_number = 0,
	    pow = 1,			/* Store the various power of 10 */
	    i;

	/* Code */

	/* Determine the length of the number */
	while(number[len++] != '\0');

	/* Checking each digit of the number and adding it with its corresping power of 10 */
	for(i = len-2 ; i > -1 ; i--){

		dec_number += (number[i] - '0') * pow;
		pow *= 10;
	}

	return(dec_number);
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



void translateBinTrameToHexa(int trameBin[], char trameHexa[]){

	/* Variables */

	int i, j;
	int bin_halfword[4];

	/* Code */

	for(i = 0; i < 8; i++){

		for(j = 0 ; j < 4 ; j++)
			bin_halfword[j] = trameBin[4*i + j];

		trameHexa[i] = binToHexa(bin_halfword);
	}
}



char binToHexa(int bin_halfword[]){

	/* Variables */

	char hexa_char;
	int dec_value;

	/* Code */

	dec_value = binToDec(bin_halfword, 4);

	switch(dec_value){

		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			hexa_char = '0' + dec_value;
			break;

		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			hexa_char = 'a' + (dec_value - 10);
			break;
	}

	return(hexa_char);
}



int binToDec(int bin_word[], int len){

	/* Variables */

	int i,
	    dec_number = 0,
	    pow = 1;

	/* Code */

	for(i = len-1 ; i > -1 ; i--){

		dec_number += bin_word[i] * pow;
		pow *= 2;
	}

	return(dec_number);
}



void decToBinTrame(int number, int trame[], int trame_len){

	/* Variables */

	int i = 0,
	    negative = 0;

	int *temp = NULL;

	/* Code */

	temp = (int *) malloc(trame_len * sizeof(int));

	/* Cleaning the memory before using it */
	for(i = 0 ; i < trame_len ; i++)
		temp[i] = 0;

	if(number < 0){
		number *= -1;
		negative = 1;
	}

	i = 0;
	while(number != 0){

		temp[i] = number % 2;
		number /= 2;
		i++;
	}

	/* Inverting the bit trame to have it in the good order */
	for(i = trame_len - 1 ; i > -1 ; i--){

		trame[trame_len - 1 - i] = temp[i];
	}

	/* If the original number was negative, uses the binary two's complement to code it */
	if(negative){

		/* First, taking the complement of the trame */
		for(i = 0 ; i < trame_len ; i++){
			if(trame[i] == 0){
				trame[i] += 1;
			}
			else{
				trame[i] -= 1;
			}
		}

		/* Then, add one to the trame */
		i = trame_len - 1;
		do
		{
			trame[i] += 1;
			if(trame[i] == 2){
				trame[i] = 0;
			}

			i--;

		}while(trame[i+1] != 1 && i>0);

	}

	free(temp);
}



instr idInstr(char *instr){

	/* Variables */

	char instructions[27][INSTR_MAX_LEN] = {"ADD", "ADDI", "AND", "BEQ", "BGTZ", "BLEZ", "BNE", "DIV", "J", "JAL", "JR", "LUI", "LW", "MFHI", "MFLO", "MULT", "NOP", "OR", "ROTR", "SLL", "SLT", "SRL", "SUB", "SW", "SYSCALL", "XOR", "EXIT"};

	int i;

	/* Code */

	for(i = 0 ; i < 27 ; i++){

		if(!strcmp(instr, instructions[i])){
			return(i);
		}
	}

	return(ERROR);
}



void addTrame(int trameBin[], int index, int trame[], int trame_lengh){

	/* Variables */

	int i;

	/* Code */

	for (i = 0; i < trame_lengh; i++){
		trameBin[index + i] = trame [i];
	}
}



void initTrame(int trameBin[], int length){

		/* Variables */

	int i;

	/* Code */

	for (i=0; i < length; i++){
		trameBin[i] = 0;
	}
}



void addRegCode(FILE* file, int bin_trame[], int index){

	/* Variables */

	int reg_trame[TRAME_REG_LEN];

	/* Code */

	initTrame(reg_trame, TRAME_REG_LEN);

	decToBinTrame(readRegister(file), reg_trame, TRAME_REG_LEN);
	addTrame(bin_trame, index, reg_trame, TRAME_REG_LEN);
}



void addImmValueCode(FILE* file, int bin_trame[], int index){

	/* Variables */

	int imm_val_trame[TRAME_IMM_LEN];

	/* Code */

	initTrame(imm_val_trame, TRAME_IMM_LEN);

	decToBinTrame(readImmValue(file), imm_val_trame, TRAME_IMM_LEN);
	addTrame(bin_trame, index, imm_val_trame, TRAME_IMM_LEN);
}



void addAddressCode(FILE* file, int bin_trame[], int index){

	/* Variables */

	int address_trame[TRAME_ADDRESS_LEN];

	/* Code */

	initTrame(address_trame, TRAME_ADDRESS_LEN);

	decToBinTrame(readImmValue(file), address_trame, TRAME_ADDRESS_LEN);
	addTrame(bin_trame, index, address_trame, TRAME_ADDRESS_LEN);
}
