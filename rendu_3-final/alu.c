
#include "constantes.h"
#include "alu.h"



void add(Operands operands){

	/* Variables */
int var1, var2, result;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);
result = var1 + var2;

if (result)
/*Writing result into register */
writeRegister (Operands.rd, var1 + var2);
}



void addi(Operands operands){
  /* Variables */
int var;

/* Code */

/*Recovering values*/
var = readRegister (operands.rs);

/*Writing result into register */
writeRegister (Operands.rt, var + immediate);
}



void and_instr(Operands operands){
  /* Variables */
int var1, var2;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);

/*Writing result into register */
writeRegister (Operands.rd, var1 & var2);
}



void beq(Operands operands){
  /* Variables */
int var1, var2, prog_counter;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);

/*Writing result into register */
  if (var1 == var2){
    prog_counter = readRegister (PROGRAM_COUNTER);
    writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
  }
}



void bgtz(Operands operands){
  /* Variables */
int var, prog_counter;

/* Code */

/*Recovering values*/
var = readRegister (operands.rs);

/*Writing result into register */
  if (var > 0){
    prog_counter = readRegister (PROGRAM_COUNTER);
    writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
  }
}



void blez(Operands operands){
  /* Variables */
int var, prog_counter;

/* Code */

/*Recovering values*/
var = readRegister (operands.rs);

/*Writing result into register */
  if (var <= 0){
    prog_counter = readRegister (PROGRAM_COUNTER);
    writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
  }
}


void bne(Operands operands){
  /* Variables */
int var1, var2, prog_counter;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);

/*Writing result into register */
  if (var1 != var2){
    prog_counter = readRegister (PROGRAM_COUNTER);
    writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
  }
}




void jump(Operands operands){

}



void nop(Operands operands){

  int prog_counter = readRegister (PROGRAM_COUNTER);
  writeRegister (PROGRAM_COUNTER, prog_counter + 4);
}


void or_instr(Operands operands){
  /* Variables */
int var1, var2;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);

/*Writing result into register */
writeRegister (Operands.rd, var1 | var2);
}



void sub(Operands operands){
  /* Variables */
int var1, var2;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);

/*Writing result into register */
writeRegister (Operands.rd, var1 - var2);
}



void xor(Operands operands){
  /* Variables */
int var1, var2;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);

/*Writing result into register */
writeRegister (Operands.rd, var1 ^ var2);
}
