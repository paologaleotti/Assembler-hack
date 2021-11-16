#ifndef SYMBOL
#define SYMBOL

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
void print_list(listsymbol *head);
void push_predefined(listsymbol **head);
int check_label(listsymbol *head, char* label);
char* dont_lose_my_string(const char *src);

#endif