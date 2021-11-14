#ifndef TRANSLATION
#define TRANSLATION

typedef struct{
	char *hack;
	int bin;
} keymap;
// search "str" in the keymap "map" and returns the "str" in its binary form
int linear_search(keymap* map, int size, char* str);

// 
int return_translated(char *str, int instrtype);

#endif