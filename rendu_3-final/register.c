
#include "constantes.h"
#include "register.h"

/* Declairing global array representing the registers */
extern int registers[NB_REGISTERS];



int readMIPSRegister (int reg_number){
  return (registers[reg_number]);
}



void writeRegister (int reg_number, int value){
  /* register 0 is always equal to 0, even after an writing */
  if (reg_number == 0){
    registers[reg_number] = 0;
  }
  else {
    registers[reg_number] = value;
  }
}


void initializingRegisters(){

	/* Putting 0 in $0 */
	registers[0] = 0;

	/* Setting the Program Counter to the text memory start address */
	registers[PROGRAM_COUNTER] = TEXT_MEMORY_START_ADDR;
}
