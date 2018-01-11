
#include "constantes.h"
#include "register.h"



int readRegister (int reg_number){
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



void printRegister (){
  int index ;
  for (index = 0; index <=NB_REGISTERS; index++){
    printf("Registre n°%d = %d\n",index,registres[index]);
  }
}
