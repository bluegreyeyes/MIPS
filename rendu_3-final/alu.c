
#include "constantes.h"
#include "register.h"
#include "memory.h"
#include "alu.h"

extern int overflow_counter;


void add(Operands operands){

	 /* Variables */
  int var1, var2, result;

  /* Code */

  /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);
  result = var1 + var2;

  if (result <= REGISTER_MAX_VALUE){
      /*Writing result into register */
    writeRegister (operands.rd, var1 + var2);
  } else {
    overflow_counter++;
  }
}


void addi(Operands operands){
    /* Variables */
  int var, result;

  /* Code */

    /*Recovering values*/
  var = readMIPSRegister (operands.rs);
  result = var + operands.immediate;

  if (result <= REGISTER_MAX_VALUE){
      /*Writing result into register */
    writeRegister (operands.rt, result);
  } else {
    overflow_counter++;
  }
}



void and_instr(Operands operands){
    /* Variables */
  int var1, var2;

  /* Code */

    /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);

    /*Writing result into register */
  writeRegister (operands.rd, var1 & var2);
}



void beq(Operands operands){
    /* Variables */
  int var1, var2, prog_counter, offset;

  /* Code */

    /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);

  offset = operands.offset <= 32767 ? operands.offset : operands.offset - 65536;

  prog_counter = readMIPSRegister (PROGRAM_COUNTER);

    /*Writing result into register */
  if (var1 == var2){
    writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
  }
  else{
	  writeRegister(PROGRAM_COUNTER, prog_counter + 4);
  }
}



void bgtz(Operands operands){
      /* Variables */
    int var, prog_counter, offset;

    /* Code */

      /*Recovering values*/
    var = readMIPSRegister (operands.rs);

    offset = operands.offset <= 32767 ? operands.offset : operands.offset - 65536;

    prog_counter = readMIPSRegister (PROGRAM_COUNTER);

      /*Writing result into register */
    if (var > 0){
      writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
    } else {
	     writeRegister(PROGRAM_COUNTER, prog_counter + 4);
    }
}



void blez(Operands operands){
    /* Variables */
  int var, prog_counter, offset;

  /* Code */

    /*Recovering values*/
  var = readMIPSRegister (operands.rs);

  offset = operands.offset <= 32767 ? operands.offset : operands.offset - 65536;

  prog_counter = readMIPSRegister (PROGRAM_COUNTER);

    /*Writing result into register */
  if (var <= 0){
    writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
  } else {
	  writeRegister(PROGRAM_COUNTER, prog_counter + 4);
  }
}


void bne(Operands operands){
    /* Variables */
  int var1, var2, prog_counter, offset;

    /* Code */

    /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);

    /* Calculating offset */
  offset = operands.offset <= 32767 ? operands.offset : operands.offset - 65536;

  prog_counter = readMIPSRegister (PROGRAM_COUNTER);

/*Writing result into register */
  if (var1 != var2){
    writeRegister (PROGRAM_COUNTER, prog_counter + (1 + offset)*4);
  } else {
	  writeRegister(PROGRAM_COUNTER, prog_counter + 4);
  }
}


void div(Operands operands){
  /* Variables */
  int var1, var2, quotient, rest;

  /* Code */

  /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);

  /*Writing result into register */
  writeRegister (LO, var1 / var2);
  writeRegister (HI, var1 % var2);
}


void jump(Operands operands){

}


void jal(Operands operands){

}

void jr(Operand operands){
  /* Variables */
  int var;

  /* Code */

  /*Recovering values*/
  var = readMIPSRegister (operands.rs);

    /*Writing result into the Program Counter */
  writeRegister(PROGRAM_COUNTER, var);
}


void lui(Operand operands){
  
}


void nop(Operands operands){

  int prog_counter = readMIPSRegister (PROGRAM_COUNTER);
  writeRegister (PROGRAM_COUNTER, prog_counter + 4);
}


void or_instr(Operands operands){
    /* Variables */
  int var1, var2;

    /* Code */

    /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);

    /*Writing result into register */
  writeRegister (operands.rd, var1 | var2);
}



void sub(Operands operands){
    /* Variables */
  int var1, var2;

    /* Code */

    /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);

    /*Writing result into register */
  writeRegister (operands.rd, var1 - var2);
}



void xor(Operands operands){
      /* Variables */
    int var1, var2;

      /* Code */

      /*Recovering values*/
    var1 = readMIPSRegister (operands.rs);
    var2 = readMIPSRegister (operands.rt);

      /*Writing result into register */
    writeRegister (operands.rd, var1 ^ var2);
}
