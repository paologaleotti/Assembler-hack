#ifndef LISTBUILDER_H
#define LISTBUILDER_H

typedef struct{
	char* label;
	int address;
} symboltable;

typedef struct listsymbol {
	char* label;
	int address;
	struct listsymbol *next;
} listsymbol;


void push_to_list(listsymbol **head, char* label, int address);
void push_predefined(listsymbol **head);
int check_label(listsymbol *head, char* label);
char* dont_lose_my_string(const char *src);
int process_variable(listsymbol* ll, char* str, int ramCounter);

#endif