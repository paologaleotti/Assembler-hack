#include "utilities.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* change_extension(char* outputfilename, char* filename, char* extension) {
	size_t len = strlen(filename);
	strcpy(outputfilename, filename);
	outputfilename[len-4] = 0;
	strcat(outputfilename, extension);
	return outputfilename;
}

void stringcleaner(char* string) {
	int i = 0;
	int j = 0;
	while (string[i] != '\0') {
		if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n') {
			string[j] = string[i];
			j++;
		}
		i++;
	}
	string[j] = 0;
	// rimuovo dallo '/' in poi
	i = 0;
	while(string[i] != '\0') {
		if (string[i] == '/') {
			string[i] = 0;
			break;
		}
		i++;
	}
}

char* int_to_binary(char* retvalue, int value) {
	for (int i = 15; i >= 0; i--) {
		retvalue[i] = (value % 2) + '0';
		value /= 2;
	}
	return retvalue;
}

int search_char_in_string(char *string, char ch){
	for (int i = 0; i < strlen(string); i++){
		if (string[i]==ch){
			return i;
		}	
	}
	return -1;
}

char* allocate_duplicated_string(const char *source) {
	char *destination = malloc(strlen (source) + 1);
	if (destination == NULL){
		return NULL;
	}
	strcpy(destination, source);
	return destination;
}
