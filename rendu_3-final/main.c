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
	int interactive_mode,		/* Flag watching the interactive status of the emulator */
	    typed_instr;

	char hex_file[FILENAME_LEN + 4];

	instr opcode;

	Operands operands;

	/* Code */

	/* Checking if an argument was passed to the program */
	if(argc > 1){

		if(strlen(argv[1]) > FILENAME_LEN){

			printf("Filename is too long ! Please use a %d characters long filename.\n", FILENAME_LEN);
			exit(1);
		}

		interactive_mode = 0;

		/* Trad du fichier fourni en hexa */
		/* Nom du fichier : hex_file */
		hex_file = translateInstructionFileToHexa(argv[1]);

		loadInstructionsInMemory(hex_file);

	}
	else{

		interactive_mode = 1;
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

		}

		/* Incrementing Program Counter */
		updateProgramCounter();

	/* Simulation currently stopping on a NOP statement */
	}while(readRegister(INSTR_REGISTER) != 0);


	return(0);
}
