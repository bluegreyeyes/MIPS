
#include "constantes.h"
#include "register.h"
#include "memory.h"
#include "alu.h"
#include <string.h>

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
  result = var + (operands.immediate <= 32767 ? operands.immediate : operands.immediate - 65536);

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


void div_instr(Operands operands){
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
  /* Variables */
  int var;

  /* Code */

  /*Recovering values*/
  var = readMIPSRegister (operands.target);

  /*Writing result into register */
  writeRegister (PROGRAM_COUNTER, var);
}


void jr(Operands operands){
  /* Variables */
  int var;

  /* Code */

  /*Recovering values*/
  var = readMIPSRegister (operands.rs);

    /*Writing result into the Program Counter */
  writeRegister(PROGRAM_COUNTER, var);
}


void lui(Operands operands){
  /* Variables */
  int var;

  /* Code */

  /*Recovering values*/
  var = readMIPSRegister (operands.immediate) << 16 ;

  /*Writing result into the Program Counter */
writeRegister(operands.rt, var);
}

void load (Operands operands){
  /* Variables */
  int var, offset;

  /* Code */

  /*Recovering values*/
  var = readMIPSRegister (operands.base);
  offset = (operands.offset - STACK_MEMORY_START_ADDR)/4;

  /*Writing result */
  writeRegister(readMIPSRegister(operands.rt), var + offset);
}


void mfhi(Operands operands){
  /* Variables */
  int var;

  /* Code */

  /*Recovering values*/
  var = readMIPSRegister (HI);

  /*Writing result into register */
  writeRegister (operands.rd, var);
}


void mflo(Operands operands){
  /* Variables */
  int var;

  /* Code */

  /*Recovering values*/
  var = readMIPSRegister (LO);

  /*Writing result into register */
  writeRegister (operands.rd, var);
}

void mult(Operands operands){
  /* Variables */
  long int var1, var2, result, hi, lo;

  /* Code */

  /*Recovering values*/
  var1 = readMIPSRegister (operands.rs);
  var2 = readMIPSRegister (operands.rt);

  result = var1*var2;
  hi = result && 0xFFFFFFFFF00000000 >> 32;
  lo = result && 0x000000000FFFFFFFF;

  /*Writing result into register */
  writeRegister (LO, lo);
  writeRegister (HI, hi);
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

void store(Operands operands){
  /* Variables */
int offset, var;

  /* Code */

  /*Recovering values*/
var = readMIPSRegister (operands.rt);
offset = (operands.offset - STACK_MEMORY_START_ADDR)/4;

  /*Writing result into register */
writeRegister(readMIPSRegister(operands.base) + offset, var);
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
