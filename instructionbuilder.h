#ifndef INSTRUCTIONBUILDER_H
#define INSTRUCTIONBUILDER_H

// definisco la struttura della keymap contenente ile istruzioni e relativo
// INTERO da convertire poi in binario. In questo modo non utilizzo le stringhe
// e il processo di conversione è facilitato dato che la riga finale tradotta
// sarà la somma di tutte le conversioni. (vedi main.c - process_C_instr)
typedef struct{
	char *hack;
	int to_convert;
} keymap;

// ricerca la stringa nella mappa e restituisce -1 se non viene trovata e l'intero associato se trovata.:
int search_instruction(keymap* map, int size, char* str);

// a seconda del tipo di istruzione, la cerca nella keymap giusta e 
//ritorna il corrispondente valore intero (da convertire in bin. successivamente):
int return_integer_C_instruction(char *str, char typeOfInstruction);

#endif