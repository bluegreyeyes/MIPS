
#include "constantes.h"
#include "alu.h"



void add(Operands operands){

	/* Variables */
int var1, var2;

/* Code */

/*Recovering values*/
var1 = readRegister (operands.rs);
var2 = readRegister (operands.rt);

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

}



void bgtz(Operands operands){
}



void jump(Operands operands){

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
