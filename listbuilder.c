#include "listbuilder.h"

#include <string.h>
#include <stdlib.h>

symboltable PREDEFINED[23] = {
	"SP", 0, "LCL", 1, "ARG", 2, "THIS", 3, "THAT", 4,
	"R0", 0, "R1", 1, "R2", 2, "R3", 3, "R4", 4, "R5", 5, "R6", 6, "R7", 7, "R8", 8, "R9", 9, "R10", 10, "R11", 11, "R12", 12, "R13", 13, "R14", 14, "R15", 15,
	"SCREEN", 16384, "KBD", 24576
};

char* dont_lose_my_string(const char *src) {
	char *dst = malloc(strlen (src) + 1); 	 	// alloca spazio per la stringa
	if (dst == NULL){							// non c'è memoria per la destinazione?
		return NULL;
	}
	strcpy(dst, src);                     		// copia la stringa
	return dst;                            		// ritorna la nuova stringa
}


void push_to_list(listsymbol **head, char* label, int address) {
	
	listsymbol *current = *head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = (listsymbol*)malloc(sizeof(listsymbol));
	current->next->label = dont_lose_my_string(label);
	current->next->address = address;
	current->next->next = NULL;
}

void push_predefined(listsymbol **head) {
	for (int i=0; i<23; i++) {
		push_to_list(head, PREDEFINED[i].label, PREDEFINED[i].address);
	}
}

// check if the label is already in the list and return the address
int check_label(listsymbol *head, char* label) {
	listsymbol *current = head;
	while(current != NULL) {
		if (current->label!=NULL && strcmp(current->label, label) == 0) {
			return current->address;
		}
		current = current->next;
	}
	return -1;
}

int process_variable(listsymbol* ll, char* str, int ramCounter){
	ramCounter++;
	push_to_list(&ll, str, ramCounter);
	return ramCounter;
}