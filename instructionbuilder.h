#ifndef INSTRUCTIONBUILDER_H
#define INSTRUCTIONBUILDER_H

typedef struct{
	char *hack;
	int to_convert;
} keymap;

// ricerca la stringa nella mappa e restituisce -1 se non viene trovata e l'intero associato se trovata. 
int search_instruction(keymap* map, int size, char* str);

// a seconda del tipo di istruzione, la cerca nella keymap giusta e 
//ritorna il corrispondente valore intero (da convertire in bin. successivamente)
int return_integer_C_instruction(char *str, char typeOfInstruction);

#endif