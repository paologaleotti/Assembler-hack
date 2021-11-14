#include "translation.h"

struct keymap {
	char *hack, *bin;
	// *hack is the asm instruction, *bin is its binary value
} DEST[8] = {
	"", "000",
	"M", "001",
	"D", "010",
	"MD", "011",
	"A", "100",
	"AM", "101",
	"AD", "110",
	"AMD", "111"
}, JUMP[8] = {
	"", "000",
	"JGT", "001",
	"JEQ", "010",
	"JGE", "011",
	"JLT", "100",
	"JNE", "101",
	"JLE", "110",
	"JMP", "111"
}, OPERATION[28] = {
	"0", "0101010",
	"1", "0111111",
	"-1", "0111010",
	"D", "0001100",
	"A", "0110000",
	"!D", "0001101",
	"!A", "0110001",
	"-D", "0001111",
	"-A", "0110011",
	"D+1", "0011111",
	"A+1", "0110111",
	"D-1", "0001110",
	"A-1", "0110010",
	"D+A", "0000010",
	"D-A", "0010011",
	"A-D", "0000111",
	"D&A", "0000000",
	"D|A", "0010101",
	"M", "1110000",
	"!M", "1110001",
	"-M", "1110011",
	"M+1", "1110111",
	"M-1", "1110010",
	"D+M", "1000010",
	"D-M", "1010011",
	"M-D", "1000111",
	"D&M", "1000000",
	"D|M", "1010101"
};

// search "str" in the keymap "map" and returns the "str" in its binary form
char* linear_search(const struct keymap *map, int size, const char* str) {
	for (int i=0; i<size; i++) {
		if (strcmp(map[i].hack, str) == 0) {
			return map[i].bin;
		}
	}	
	return "NULL";
}

char* return_binary(char *str, char instrtype){
	char* translated;

	switch (instrtype){
	case 'J':
		translated =  linear_search(JUMP, 8, str);
		break;
	case 'D':
		translated = linear_search(DEST, 8, str);
		break;
	case 'O':
		translated = linear_search(OPERATION, 28, str);
		break;
	return translated;
}