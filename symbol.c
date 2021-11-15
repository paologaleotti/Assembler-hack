#include "symbol.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

symboltable PREDEFINED[23] = {
	"SP", 0, "LCL", 1, "ARG", 2, "THIS", 3, "THAT", 4,
	"R0", 0, "R1", 1, "R2", 2, "R3", 3, "R4", 4, "R5", 5, "R6", 6, "R7", 7, "R8", 8, "R9", 9, "R10", 10, "R11", 11, "R12", 12, "R13", 13, "R14", 14, "R15", 15,
	"SCREEN", 16384, "KBD", 24576
};

void push_to_listsymbol(list_t *head, char* label, int address) {
	list_t *current = head;
   	while(current->next != NULL) {
		current = current->next;
	}
	current->next = (list_t*)malloc(sizeof(list_t));
	current->next->label = label;
	current->next->address = address;
	current->next->next = NULL;
}

// function to return the address of the symbol
int get_address(list_t *head, char* label) {
	list_t * current = head;
	while (current != NULL) {
		if (strcmp(current->label, label) == 0) {
			return current->address;
		}
		current = current->next;
	}
	return -1;
}

// function to push PREDEFINED in listsymbol
void push_predefined(list_t *head) {
	for (int i=0; i<23; i++) {
		push_to_listsymbol(head, PREDEFINED[i].label, PREDEFINED[i].address);
	}
}

// function that prints listsymbolF
void print_listsymbol(list_t *head) {
	list_t * current = head;
	while (current != NULL) {
		printf("%s %d\n", current->label, current->address);
		current = current->next;
	}
}