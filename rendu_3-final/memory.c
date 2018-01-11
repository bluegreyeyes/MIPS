
#include "constantes.h"
#include "memory.h"

/* Declairing global arrays representing the memory */
extern int text_mem[TEXT_MEMORY_LEN];
extern int stack_mem[STACK_MEMORY_LEN];


int readTextMemory (int address){
  return (text_mem[address]);
}



void writeTextMemory (int address, int value){
  text_mem[address] = value;
}



int readDataMemory (int address){
  return (stack_mem[address]);
}



void writeDataMemory (int address, int value){
  stack_mem[address] = value;
}



void printStack(){

}
