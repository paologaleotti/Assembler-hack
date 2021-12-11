#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instructionbuilder.h"
#include "listbuilder.h"
#include "utilities.h"

char *process_A_instr(char *str, char *ret){
	str[0] = '0';
	int val = atoi(str);
	int_to_binary(ret, val);
	ret[16] = 0;
	return ret;
}

char *process_C_instr(char *str, char *ret){

	int sum = 0;
	if (search_char_in_string(str, ';') == -1){

		// calcolo PRIMA dell'uguale
		char before[10];

		for (int i = 0; i < search_char_in_string(str, '='); i++){
			before[i] = str[i];
		}
		sum = sum + return_integer_C_instruction(before, 'D');

		// calcolo DOPO l'uguale
		char after[10] = {0};
		int countAfter = 0;

		for (int i = search_char_in_string(str, '=') + 1; i < strlen(str); i++){
			after[countAfter++] = str[i];
		}
		sum = sum + return_integer_C_instruction(after, 'O');
	}
	else{

		char before[10];
		for (int i = 0; i < search_char_in_string(str, ';'); i++){
			before[i] = str[i];
		}
		sum = sum + return_integer_C_instruction(before, 'O');

		char after[10] = {0};
		int countAfter = 0;
		for (int i = search_char_in_string(str, ';') + 1; i < strlen(str); i++){
			after[countAfter++] = str[i];
		}
		sum = sum + return_integer_C_instruction(after, 'J');
	}

	sum = sum + 57344; // aggiungo questo valore per mettere i primi bit a 111
	int_to_binary(ret, sum);
	ret[16] = 0;	// aggiungo il carattere di fine stringa
	return ret;
}

void first_pass(FILE *fin, listsymbol *ll){
	char str[200];	// riga letta dal file
	int romcounter = 0;

	while (fgets(str, 200, fin)){
		// elimino gli ultimi due caratteri perchè i file di Nand2Tetris hanno la codifica di windows (CRLF)
		str[strlen(str) - 2] = 0;
		stringcleaner(str);

		if (str[0] != 0){
			if (str[0] == '('){
				char withoutBracket[200];

				for (int i = 0, j = 0; i < strlen(str); i++){
					if (str[i] != '(' && str[i] != ')'){
						withoutBracket[j++] = str[i];
					}
					withoutBracket[j] = 0;
				}
				push_to_list(&ll, withoutBracket, romcounter);
			}
			// se è qualsiasi istruzione (NON SIMBOLO) aumento il contatore
			else{
				romcounter++;
			}
		}
	}
}

void second_pass(FILE *fin, FILE *fout, listsymbol *ll){
	int ramCounter = 15;
	char str[200];
	char ret[17];	// riga da scrivere nel file di output

	while (fgets(str, 200, fin) != NULL){
		str[strlen(str) - 2] = 0;
		stringcleaner(str);
		if (str[0] != 0 && str[0] != '('){ // ignore empty lines

			if (str[0] == '@'){
				if (str[1] >= '0' && str[1] <= '9'){
					process_A_instr(str, ret);
					fprintf(fout, "%s\n", ret);
				}
				else{
					char withoutAt[200];
					for (int i = 0; i < strlen(str); i++){
						withoutAt[i] = str[i + 1];
					}

					int addr = check_label(ll, withoutAt);

					if (addr != -1){
						int_to_binary(ret, addr);
					}
					else{
						ramCounter = process_variable(ll, withoutAt, ramCounter);
						int_to_binary(ret, ramCounter);
					}

					fprintf(fout, "%s\n", ret);
				}
			}
			else{
				//C-instruction
				process_C_instr(str, ret);
				fprintf(fout, "%s\n", ret);
			}
		}
	}
}

int main(int argc, char **argv){

	FILE *fileinput;	// dichiaro file di input
	FILE *fileoutput;	// dichiaro file di output
	listsymbol *ll = malloc(sizeof(listsymbol)); // dichiaro la symbol table

	char outputfilename[strlen(argv[1]) + 2]; // genero il nome del file di output

	change_extension(outputfilename, argv[1], ".hack");	// cambio l'estensione del file di output a ".hack"

	fileinput = fopen(argv[1], "r");
	fileoutput = fopen(outputfilename, "w");

	push_predefined(&ll);	// inserisco nella symbol table i simboli predefiniti del linguaggio hack

	printf("--------Processo il file '%s'---------\n", argv[1]);

	first_pass(fileinput, ll);
	rewind(fileinput);	// torno all'inizio del fileinput
	second_pass(fileinput, fileoutput, ll);
	printf("[FATTO]'%s' è stato tradotto con successo nel file --> '%s'\n", argv[1], outputfilename);

	fclose(fileinput);
	fclose(fileoutput);
	return 0;
}