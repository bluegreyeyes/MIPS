
#include "constantes.h"
#include "register.h"



int readRegister (int reg_number){
  return (registers[reg_number]);
}



void writeRegister (int reg_number, int value){
  registers[reg_number] = value;
}



void printRegister (){

}
