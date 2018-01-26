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
		switch (index){
			case 32 :
				printf("Program counter = %d\n",index,readMIPSRegister(index));
				break;

			case 33 :
				printf("Instruction register = %d\n",index,readMIPSRegister(index));
				break;


			case 34 :
				printf("Register LO = %d\n",index,readMIPSRegister(index));
				break;

			case 35 :
				printf("Register HI = %d\n",index,readMIPSRegister(index));
				break;

			default :
    		printf("Registre n°%d = %d\n",index,readMIPSRegister(index));
				break;
		}
  }
}



void displayMemoryState(){

	int i;

	printf("#########################\n");

	for(i = 0; i < NB_REGISTERS; i++){

		if(i != PROGRAM_COUNTER && i != INSTR_REGISTER){

			printf("# %2d | %8d ## %8x : %8x #\n", i, readMIPSRegister(i), STACK_MEMORY_START_ADDR + 4*i, readDataMemory(i));

		}
		else{

			printf("# %2d | %8x ## %8x : %8x #\n", i, readMIPSRegister(i), STACK_MEMORY_START_ADDR + 4*i, readDataMemory(i));

		}

		printf("#---------------## %8x : %8x #\n", STACK_MEMORY_START_ADDR + 4*(i+1), readDataMemory(i));

	}
}
