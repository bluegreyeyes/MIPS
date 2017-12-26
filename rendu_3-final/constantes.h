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
	int rt;		/* Second sosurce or destination register (depends on the instruction) */
	int immediate;	/* Immediate value */
	int offset;	/* Offset valeur */
	int target;	/* Jump value (for J and JAL instructions) */

} Operands;

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

#endif
