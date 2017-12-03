#include <stdio.h>
#include <string.h>

#include "trad.h"

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
