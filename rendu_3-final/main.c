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
#include <stdlib.h>
#include <string.h>

#include "constantes.h"
#include "UI.h"
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

/* Overflow count */
int overflow_counter = 0;



int main(int argc, char *argv[]){

	/* Variables */
	int interactive_mode,		/* Flag watching the interactive status of the emulator */
	    step_mode = 0,		/* Step mode flag */
	    branch_instr,		/* Branch or jump instruction flag */
	    typed_instr,
	    instr_count = 1;

	char *hex_file = NULL;

	instr opcode;

	Operands operands;

	/* Code */

	initializingRegisters();

	/* Checking if an argument was passed to the program */
	if(argc > 1){

		if(strlen(argv[1]) > FILENAME_LEN){

			printf("Filename is too long ! Please use a %d characters long filename.\n", FILENAME_LEN-1);
			exit(1);
		}

		interactive_mode = 0;

		/* Translating the instruction file in hexadecimal and loading it in the memory */
		hex_file = translateInstructionFileToHexa(argv[1]);
		loadInstructionsInMemory(hex_file);

		if(argc == 3 && checkStepMode(argv[2])){

			printf("The MIPS Emulator is launched in step mode.\n");
			step_mode = 1;
		}

		/* Displaying the program's code in hexadecimal */
		printf("-----[ Program Code ]-----\n\n");
		displayProgram(0);
		printf("\n");

	}
	else{

		interactive_mode = 1;
		printf("The MIPS Emulator is launched in interactive mode.\n");
	}

	printf("-----[ Beginning of the simulation ]-----\n\n");

	do
	{
		if(interactive_mode){

			/* Récupérer l'instr tapée */
			printf("Please type your instruction : \n");

			/* La traduire en décimale */
			typed_instr = strHexaToDec(readSingleInstruction(stdin));

			/* La placer dans le registre d'instruction */
			writeRegister(INSTR_REGISTER, typed_instr);

		}
		else{

			loadCurrentInstruction();

			printf("--[ Step  %-d ]--\n", instr_count);
			displayProgram(1);
			printf("\n");
		}

		/* Filling the Operands structure */
		readOperands(&operands);

		/* Reseting branch flag */
		branch_instr = 0;

		if(step_mode){
			printf("Instruction en attente :\n");
		}

		switch(idInstruction()){

			case ADD:
				if(step_mode){
					printf("ADD $%d, $%d, $%d\n", operands.rd, operands.rs, operands.rt);
				}
				add(operands);
				break;

			case ADDI:
				if(step_mode){
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
				branch_instr = 1;
				beq(operands);
				break;

			case BGTZ:
				if(step_mode){
					printf("BGTZ $%d, %d\n", operands.rs, operands.offset <= 32767 ? operands.offset : operands.offset - 65536);
				}
				branch_instr = 1;
				bgtz(operands);
				break;

			case BLEZ:
				if(step_mode){
					printf("BLEZ $%d, %d\n", operands.rs, operands.offset <= 32767 ? operands.offset : operands.offset - 65536);
				}
				branch_instr = 1;
				blez(operands);
				break;

			case BNE:
				if(step_mode){
					printf("BNE $%d, $%d, %d\n", operands.rs, operands.rt, operands.offset <= 32767 ? operands.offset : operands.offset - 65536);
				}
				branch_instr = 1;
				bne(operands);
				break;

			case DIV:
				if(step_mode){
					printf("DIV $%d, $%d\n", operands.rs, operands.rt);
				}
				div_instr(operands);
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
				jr(operands);
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
				xor(operands);
				break;

		}

		/* Waiting for the user to "validate" the move to the next instruction */
		if(step_mode){
			waitUserGo();
		}

		instr_count++;
		
		/* Afficher l'état des registres et de la mémoire data en mode intéractif et pas à pas */
		if(interactive_mode || step_mode){

			printf("-----[ Registers' state ]-----\n");
			//printRegister();
			displayMemoryState();
			printf("\n");

 		}

		/* Incrementing Program Counter if no branch instruction occured */
		if(!branch_instr){
			updateProgramCounter();
		}

	/* Simulation currently stopping on a NOP statement */
	}while(readMIPSRegister(INSTR_REGISTER) != EXIT_INSTR);

	/* Affichage de la mémoire et des registres à la fin de l'émulation */
	printf("-----[ Final state of the registers ]-----\n");
	printRegister();
	printf("\n");

	//printf("-----[ Finale state of the data mem ]-----\n");
	/* TODO : Afficher mémoire data */

	printf("-----[ End of the simulation ]-----\n");

	return(0);
}
