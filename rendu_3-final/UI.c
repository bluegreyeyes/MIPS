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



void displayProgram(int displayCurrentPos){

	int i = 0,
	    current_instr_offset = (readMIPSRegister(PROGRAM_COUNTER) - TEXT_MEMORY_START_ADDR)/4,
	    instr = readTextMemory(0);

	while(instr != EXIT_INSTR){

		printf("0x%08X : %08X", TEXT_MEMORY_START_ADDR + 4*i, instr);

		if(displayCurrentPos && i == current_instr_offset){
			printf(" <=\n");
		}
		else{
			printf("\n");
		}

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



