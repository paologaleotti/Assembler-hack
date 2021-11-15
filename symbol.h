#ifndef SYMBOL
#define SYMBOL



typedef struct{
	char* label;
	int address;
} symboltable;

typedef struct listsymbol {
	char* label;
    int address;
    struct listsymbol * next;
} list_t;

void push_to_listsymbol(list_t *head, char* label, int value);

int get_address(list_t *head, char* label);

void push_predefined(list_t *head);

void print_listsymbol(list_t *head);

#endif