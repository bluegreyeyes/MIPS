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
