/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * =================================================
 */

#include <stdio.h>
#include <string.h>

#include "constantes.h"
#include "file.h"
#include "trad.h"
#include "loadInstr.h"
#include "instructions.h"
#include "register.h"
#include "memory.h"
#include "alu.h"

/* Declaration of the global arrays which will emulate the memory and registers of the MIPS */
int registers[NB_REGISTERS];
int text_mem[TEXT_MEMORY_LEN];
int stack_mem[STACK_MEMORY_LEN];



int main(int argc, char *argv[]){
	 
	/* Variables */
	int interactive_mode,		/* Interactive status of the emulator flag */
	    step_mode,			/* Step mode flag */
	    typed_instr;

	char hex_file[FILENAME_LEN + 4];

	instr opcode;

	Operands operands;

	/* Code */

	/* Checking if an argument was passed to the program */
	if(argc > 1){

		if(strlen(argv[1]) > FILENAME_LEN){

			printf("Filename is too long ! Please use a %d characters long filename.\n", FILENAME_LEN - 1);
			exit(1);
		}

		interactive_mode = 0;

		/* Transalating the instruction file in hexadecimal */
		hex_file = translateInstructionFileToHexa(argv[1]);

		loadInstructionsInMemory(hex_file);

		if(argc == 3 && checkStepMode(argv[2])){

			step_mode = 1;
			printf("The MIPS emulator is launched in step mode.\n");
		}
		else{
			
			step_mode = 0;
		}
	}
	else{

		interactive_mode = 1;
	}

	/* Display the program in hexadecimal code if a file is provided */
	if(!interactive_mode){

		printf("-----[Program's hexadecimal translation]-----\n\n");
		displayProgram();
	}

	do
	{
		if(interactive_mode){

			/* Récupérer l'instr tapée */

			/* La traduire en décimale */

			/* La placer dans le registre d'instruction */
			writeRegister(INSTR_REGISTER, typed_instr);

		}
		else{

			loadCurrentInstruction();
		}

		/* Filling the Operands structure */
		readOperands(&operands);

		switch(idInstr()){

			case ADD:
				if(step_mode){
					printf("ADD $%d, $%d, $%d\n", operands.rd, operands.rs, operands.rt);
				}
				add(operands);
				break;

			case ADDI:
				id(step_mode){
					printf("ADDI $%d, $%d, %d\n", operands.rt, operands.rs, operands.immediate <= 32767 ? operands.immediate : operands.immediate - 65536);
				}
				addi(operands);
				break;

			case AND:
				if(step_mode){
					printf("AND $%d, $%d, $%d\n", operands.rd, operands.rs, operands.rt);
				}
				and_instr(operands);
				break;

			case BEQ:
				if(step_mode){
					printf("BEQ $%d, $%d, %d\n", operands.rs, operands.rt, operands.offset <= 32767 ? operands.offset : operands.offset - 65536);
				}
				beq(operands);
				break;

			case BGTZ:
				if(step_mode){
					printf("BGTZ $%d, %d\n", operands.rs, operands.offset <= 32767 ? operands.offset : operands.offset - 65536);
				}
				bgtz(operands);
				break;

			case BLEZ:
				if(step_mode){
					printf("BLEZ $%d, $%d, $%d\n", operands.rd, operands.rs, operands.offset <= 32767 ? operands.offset : operands.offset - 65536);
				}
				blez(operands);
				break;

			case BNE:
				if(step_mode){
					printf("BNE $%d, $%d, %d\n", operands.rs, operands.rt, operands.offset <= 32767 ? operands.offset : operands.offset - 65536);
				}
				bne(operands);
				break;

			case DIV:
				if(step_mode){
					printf("DIV $%d, $%d\n", operands.rs, operands.rt);
				}
				/*TODO div(operands);*/
				break;

			case J:
				if(step_mode){
					printf("J %d\n", operands.target);
				}
				/*TODO jump(operands);*/
				break;

			case JAL:
				if(step_mode){
					printf("JAL %d\n", operands.target);
				}
				/*TODO jal(operands);*/
				break;

			case JR:
				if(step_mode){
					printf("JR $%d\n", operands.rs);
				}
				/*TODO jr(operands);*/
				break;

			case LUI:
				if(step_mode){
					printf("LUI $%d, %d\n", operands.rt, operands.immediate <= 32767 ? operands.immediate : operands.immediate - 65536);
				}
				/*TODO lui(operands);*/
				break;

			case LW:
				if(step_mode){
					printf("LW $%d, %d($%d)\n", operands.rt, operands.offset <= 32767 ? operands.offset : operands.offset - 65536, operands.base);
				}
				/*TODO lw(operands);*/
				break;

			case MFHI:
				if(step_mode){
					printf("MFHI $%d\n", operands.rd);
				}
				/*TODO mfhi(operands);*/
				break;

			case MFLO:
				if(step_mode){
					printf("MFLO $%d\n", operands.rd);
				}
				/*TODO mflo(operands);*/
				break;

			case MULT:
				if(step_mode){
					printf("MULT $%d, $%d\n", operands.rs, operands.rt);
				}
				/*TODO mult(operands);*/
				break;

			case NOP:
				if(step_mode){
					printf("NOP\n");
				}
				break;

			case OR:
				if(step_mode){
					printf("OR $%d, $%d, $%d\n", operands.rd, operands.rs, operands.rt);
				}
				or_instr(operands);
				break;

			case ROTR:
				if(step_mode){
					printf("ROTR $%d, $%d, %d\n", operands.rd, operands.rt, operands.sa);
				}
				/*TODO rotr(operands);*/
				break;

			case SLL:
				if(step_mode){
					printf("SLL $%d, $%d, %d\n", operands.rd, operands.rt, operands.sa);
				}
				/*TODO sll(operands);*/
				break;

			case SLT:
				if(step_mode){
					printf("SLT $%d, $%d, $%d\n", operands.rd, operands.rs, operands.rt);
				}
				/*TODO slt(operands);*/
				break;

			case SRL:
				if(step_mode){
					printf("SRL $%d, $%d, %d\n", operands.rd, operands.rt, operands.sa);
				}
				/*TODO srl(operands);*/
				break;

			case SUB:
				if(step_mode){
					printf("SUB $%d, $%d, $%d\n", operands.rd, operands.rs, operands.rt);
				}
				sub(operands);
				break;

			case SW:
				if(step_mode){
					printf("SW $%d, %d($%d)\n", operands.rt, operands.offset <= 32767 ? operands.offset : operands.offset - 65536, operands.base);
				}
				/*TODO sw(operands);*/
				break;

			case XOR:
				if(step_mode){
					printf("XOR $%d, $%d, $%d\n", operands.rd, operands.rs, operands.rt);
				}
				/*TODO xor(operands);*/
				break;

		}

		/* Waiting for the user to "validate" the move to the next instruction */
		if(step_mode){
			waitUserGo();
		}
		
		/* Afficher l'état des registres et de la mémoire data en mode intéractif et pas à pas */
		if(interactive_mode || step_mode){

		}

		/* Incrementing Program Counter */
		updateProgramCounter();

	/* Simulation currently stopping on a NOP statement */
	}while(readRegister(INSTR_REGISTER) != 0);


	return(0);
}
