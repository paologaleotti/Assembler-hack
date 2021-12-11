#ifndef LISTBUILDER_H
#define LISTBUILDER_H

typedef struct{
	char* label;
	int address;
} symboltable;

// lista dinamica per aggiunta di simboli:
typedef struct listsymbol {
	char* label;
	int address;
	struct listsymbol *next;
} listsymbol;

// aggiunta di simbolo in CODA alla lista:
void push_to_list(listsymbol **head, char* label, int address);

// push di TUTTI i simboli predefiniti (dalla keymap)
// alla lista dinamica PRIMA di pushare qualsiasi altro simbolo non predefinito:
void push_predefined(listsymbol **head);

// controllo se un simbolo è già presente nella lista
// ritorno -1 se non presente, ritorno il suo address se presente:
int check_label(listsymbol *head, char* label);

// push nella lista di una nuova VARIABILE
// che avrà come label il nome della variabile
// e come address il CONTATORE dell'indirizzo in ram (da 16 in poi):
int process_variable(listsymbol* ll, char* str, int ramCounter);

#endif