
#include "constantes.h"
#include "instructions.h"
#include "register.h"
#include "memory.h"


void loadCurrentInstruction(){

	/* Calculating the data's offset from start address, in 32 bits words */
	int offset = (readMIPSRegister(PROGRAM_COUNTER) - TEXT_MEMORY_START_ADDR)/4;

	writeRegister(INSTR_REGISTER, readTextMemory(offset));
}



instr idInstruction(){

	/* Variables */

	int instruction = readMIPSRegister(INSTR_REGISTER),
	    opcode = 0;

	/* Code */

	/* Checking for the NOP instruction */
	if(instruction == 0)
		return NOP;

	/* Determining the position of the opcode (in first or last position) */
	if((instruction & OPCODE_MSB) == 0){

		/* Opcode is on the 6 LSB */
		opcode = instruction & OPCODE_LSB;

		switch(opcode){

			case 0b100000:
				return ADD;
			
			case 0b100100:
				return AND;
		
			case 0b011010:
				return DIV;

			case 0b001000:
				return JR;

			case 0b010000:
				return MFHI;

			case 0b010010:
				return MFLO;

			case 0b011000:
				return MULT;

			case 0b100101:
				return OR;

			case 0b000010:
				if(instruction & 0x00200000){
					return ROTR;
				}
				else{
					return SRL;
				}

			case 0b101010:
				return SLT;

			case 0b100010:
				return SUB;

			case 0b100110:
				return XOR;

			case 0b001100:
				return SYSCALL;

		}
	}
	else{

		/* Opcode is on the 6 MSB */
		opcode = instruction & OPCODE_MSB;
		opcode = opcode >> 26;

		/* We need to apply the LSB mask because the bit translation copies the MSB of the opcode (which can be a '1' */
		switch(opcode & OPCODE_LSB){

			case 0b001000:
				return ADDI;

			case 0b000100:
				return BEQ;

			case 0b000111:
				return BGTZ;

			case 0b000110:
				return BLEZ;

			case 0b000101:
				return BNE;

			case 0b000010:
				return J;

			case 0b000011:
				return JAL;

			case 0b001111:
				return LUI;

			case 0b100011:
				return LW;

			case 0b101011:
				return SW;

			case 0b000000:
				return SLL;

		}
	}
}



void readOperands (Operands *operands){

	/* Recovering the current instruction */

	int instruction = readMIPSRegister(INSTR_REGISTER);

	/* Filling the Operand structure */

	operands->rd = (instruction & 0x0000F800) >> 11;
	operands->rt = (instruction & 0x001F0000) >> 16;
	operands->rs = (instruction & 0x03E00000) >> 21;
	operands->sa = (instruction & 0x000007C0) >> 6;
	operands->base = (instruction & 0x03D00000) >> 21;
	operands->immediate = (instruction & 0x0000FFFF);
	operands->offset = (instruction & 0x0000FFFF);
	operands->target = (instruction & 0x03FFFFFF);

}



void updateProgramCounter(){

	writeRegister(PROGRAM_COUNTER, readMIPSRegister(PROGRAM_COUNTER) + 4);
}
