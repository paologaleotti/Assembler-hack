#ifndef TRANSLATION
#define TRANSLATION

// search "str" in the keymap "map" and returns the "str" in its binary form
char* linear_search(const struct keymap *map, int size, const char* str);

// 
char* return_binary(char *str, char instrtype);

#endif