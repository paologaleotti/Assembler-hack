#ifndef INSTRUCTIONBUILDER_H
#define INSTRUCTIONBUILDER_H

typedef struct{
	char *hack;
	int bin;
} keymap;
// search "str" in the keymap "map" and returns the "str" in its binary form
int linear_search(keymap* map, int size, char* str);

// 
int return_translated(char *str, char instrtype);

#endif