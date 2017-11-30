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
