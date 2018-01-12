#include <stdio.h>
#include <string.h>

#include "constantes.h"
#include "register.h"
#include "memory.h"
#include "UI.h"


int checkStepMode(char arg[]){

	if(!strcmp(arg, "-pas")){

		return(1);
	}
	else{

		return(0);
	}
}



void waitUserGo(){

	while(fgetc(stdin) != '\n'){;}
}



void displayProgram(){

	int i = 0,
	    start_addr = readMIPSRegister(PROGRAM_COUNTER),
	    instr = readTextMemory(0);

	while(instr != 0){

		printf("0x%08X : %08X\n", start_addr + 4*i, instr);

		i++;
		instr = readTextMemory(i);
	}

}



void printRegister(){
  int index ;
  for (index = 0; index < NB_REGISTERS; index++){
    printf("Registre n°%d = %d\n",index,readMIPSRegister(index));
  }
}



