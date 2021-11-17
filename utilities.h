#ifndef UTILITIES
#define UTILITIES

// cambia l'estensione da .asm dell'input a .hack
char* change_extension(char* outputfilename, char* filename, char* extension);

// funzione ausiliaria che pulisce la stringa da spazi, tab, \n e commenti
void stringcleaner(char* string);

// converto un intero in binario (stringa di 0 e 1) a 16 bit
char* int_to_binary(char* retvalue, int value);

// cerco nella stringa il carattere ch e ritorno l'indice corrispondente (-1 se non è nella stringa)
int search_char_in_string(char *string, char ch);

// funzione indispensabile per fare il push di una riga letta dal file input nella linked list
// contenente i simboli. Senza di questa il puntatore della riga verrà sovrascritto ad ogni ciclo
// di lettura del file input. Allocando memoria ad una copia della stringa (riga letta in questa iterazione),
// si evita di "perderla" e sarà quindi possibile aggiungerla alla linked list.
char* allocate_duplicated_string(const char *source);

#endif