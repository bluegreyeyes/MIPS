/*==================================================
 *
 *                - Projet MIPS -
 *
 * Contributors :
 * 	- LE POURSOT Axelle
 * 	- DESUERT Arthur
 *
 * Load Instructions Module: manage to move the code into memory.
 *    - Interaction with the file in hexadecimal.
 *    - Communication with memory
 *
 * =================================================
 */

 /* Ouvre un fichier avec le mode choisi */
 FILE* openFile(char* filename, char* mode);

 /* Ferme le fichier fourni */
 void closeFile(char* filename, FILE* file);

 /*Charge les intructions contenues dans instructions_file dans la mémoire*/
 void loadInstructionsInMemory (FILE * Instructions_file);

 /*Charge les intructions contenues dans la mémoire vers le fichier instructions_file*/
 void readInstructionsFromFile (FILE * instruction_file, char instruction[]);

 /* Tansforme une chaîne de carac. représentant un nombre hexa en nombre décimal */
 int strHexaToDec(char hexa_number[]);
