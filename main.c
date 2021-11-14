#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translation.h"

// changes the extentionfrom .asm to .hack in order to create the output file.
char* asm_to_hack(char* foutN, char* fname, char* ext) {
	size_t len = strlen(fname);
	strcpy(foutN, fname);
	foutN[len-4] = 0;
	strcat(foutN, ext);
	return foutN;
}

// transform an integer in binary and returns it inside string
char* int_to_bin(char* ret, int val) {
	for (int i = 15; i >= 0; i--) {
		ret[i] = (val % 2) + '0';
		val /= 2;
	}
	return ret;
}

// returns the index of the "charToSearch" in "str"
int string_search(char *str, char charToSearch){
	for (int i = 0; i < strlen(str); i++){
		if (str[i]==charToSearch){
			return i;
		}	
	}
	return -1;
}


// in case an A-instruction is read, this set of instruction will be executed.
char* a_instruction(char* str, char* ret) {
	str[0] = '0';
	int val = atoi(str);
	int_to_bin(ret, val);
	ret[16] = 0;
	return ret;
}

// in case a C-instrucion is read, this set of instruction will be executed.
char* c_instruction(char* str, char* ret) {

	int sum = 0;
	// if current line == "dest=operation"
	if (string_search(str, ';') == -1){	
	
		// calcolo PRIMA dell'uguale
		char before[10];
		
		for (int i = 0; i < string_search(str, '='); i++) {
			before[i] = str[i];
		}
		sum = sum + return_translated(before, 'D');
		
		// calcolo DOPO l'uguale
		char after[10] = {0};
		int countAfter = 0;
		for (int i = string_search(str, '=') + 1; i < strlen(str)-2; i++) {
			after[countAfter++] = str[i];
		}
		sum = sum + return_translated(after, 'O');
		
	}
	else {
		
		// PRIMA del ;
		char before[10];
		for (int i = 0; i < string_search(str, ';'); i++) {
			before[i] = str[i];
		}
		sum = sum + return_translated(before, 'O');

		// DOPO del ;
		char after[10] = {0};
		int countAfter = 0;
		for (int i = string_search(str, ';') + 1; i < strlen(str)-2; i++) {
			after[countAfter++] = str[i];
		}
		sum = sum + return_translated(after, 'J');
	}
	
	sum = sum + 57344; ///first '111' bits
	int_to_bin(ret, sum);

	printf("SOMMA FINALE: %d\n", sum);
	
	ret[16] = 0;
	return ret;
}

int main(int argc, char** argv) {

	FILE* fin;
	FILE* fout;

	char str[20];
	char ret[17];
	char foutName[strlen(argv[1]) + 2];

	asm_to_hack(foutName, argv[1], ".hack");

	fin = fopen(argv[1], "r");
	fout = fopen(foutName, "w");
	
	printf("Sto elaborando il file...\n");
	while (fgets(str, 20, fin) != NULL) {
		
		if (str[0] == '@') {
			
			//A-instruction
			a_instruction(str, ret);
			fprintf(fout, "%s\n", ret);

		} else {

			//C-instruction
			c_instruction(str, ret);
			fprintf(fout,"%s\n", ret);
			
		}
	}
	printf("File elaborato!\n");

	fclose(fin);
	fclose(fout);
}