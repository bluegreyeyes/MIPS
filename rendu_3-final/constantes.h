/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Constantes : Regroups the definitions of structures and constants used throughout the project
 *
 * =================================================
 */

#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

/* Structures */

/* Operands structure can store every possible operant of an instruction */
typedef struct {

	int rd;		/* Destination register */
	int rs;		/* First source register */
	int rt;		/* Second source or destination register (depends on the instruction) */
	int sa;		/* Offset value for bit-moving instructions */
	int base;	/* Register containing the base address (used by LW and SW instructions) */
	int immediate;	/* Immediate value */
	int offset;	/* Offset value */
	int target;	/* Jump value (for J and JAL instructions) */

} Operands;

/* Enumeration containing all the instructions supported, for visibility purpose */
typedef enum instr {ADD, ADDI, AND, BEQ, BGTZ, BLEZ, BNE, DIV, J, JAL, JR, LUI, LW, MFHI, MFLO, MULT, NOP, OR, ROTR, SLL, SLT, SRL, SUB, SW, SYSCALL, XOR} instr;


/* Constants */

/* MIPS' registers number */
#define NB_REGISTERS 32

/* MIPS' .text memory length */
#define TEXT_MEMORY_LEN 500

/* MIPS' .text memory starting address */
#define TEXT_MEMORY_START_ADDR 0x08040000

/* MIPS' stack length */
#define STACK_MEMORY_LEN 500

/* MIPS' stack starting address */
#define STACK_MEMORY_START_ADDR 0xBFFFFFFF

/*MIPS' Program counter */
#define PROGRAM_COUNTER

/* MIPS' Instruction Register */
#define INSTR_REGISTER 

/* Instruction's lenght */
#define INSTR_LEN 9

/* Opcode mask for MSB */
#define OPCODE_MSB 0xFC000000

/* Opcode mask for LSB */
#define OPCODE_LSB 0x0000003F

#endif
