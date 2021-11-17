#include "instructionbuilder.h"

#include <stdio.h>
#include <string.h>

keymap DEST[8] = {
	"", 0,
	"M", 8,
	"D", 16,
	"MD", 24,
	"A", 32,
	"AM", 40,
	"AD", 48,
	"AMD", 56
};
keymap JUMP[8] = {
	"", 0,
	"JGT", 1,
	"JEQ", 2,
	"JGE", 3,
	"JLT", 4,
	"JNE", 5,
	"JLE", 6,
	"JMP", 7
};
keymap OPERATION[28] = {
	"0", 2688,
	"1", 4032,
	"-1", 3712,
	"D", 768,
	"A", 3072,
	"!D", 832,
	"!A", 3136,
	"-D", 960,
	"-A", 3264,
	"D+1", 1984,
	"A+1", 3520,
	"D-1", 896,
	"A-1", 3200,
	"D+A", 128,
	"D-A", 1216,
	"A-D", 448,
	"D&A", 0,
	"D|A", 1344,
	"M", 7168,
	"!M", 7232,
	"-M", 7360, 
	"M+1", 7616,
	"M-1", 7296,
	"D+M", 4224,
	"D-M", 5312,
	"M-D", 4544,
	"D&M", 4096,
	"D|M", 5440
};

int search_instruction(keymap* map, int size, char* str) {
	for (int i=0; i<size; i++) {
		if (strcmp(map[i].hack, str) == 0) {
			return  map[i].to_convert;
		}
	}	
	return -1;
}

// switch between the three different keymaps given the instruction type (jump, dest, operation)
int return_integer_C_instruction(char *str, char typeOfInstruction) {
	int to_convert = 0;
	switch (typeOfInstruction){
	case 'J':
		to_convert =  search_instruction(JUMP, 8, str);
		break;
	case 'D':
		to_convert = search_instruction(DEST, 8, str);
		break;
	case 'O':
		to_convert = search_instruction(OPERATION, 28, str);
		break;
	}
	return to_convert;
}