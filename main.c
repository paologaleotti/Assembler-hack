#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// in case an A-instruction is read, this set of instruction will be executed.
char* a_instruction(char* str, char* ret) {
    str[0] = '0';
    int val = atoi(str);
    int_to_bin(ret, val);
    ret[16] = '\n';
    return ret;
}

// in case a C-instrucion is read, this set of instruction will be executed.
char* c_instruction(char* str, char* ret) {
    
    // IMPLEMENTA QUI IL CUT DI STRINGHE

    ret[16] = '\n';
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

    while (fgets(str, 10, fin) != NULL) {
        if (str[0] == '@') {
            
            //A-instruction
            a_instruction(str, ret);
            fprintf(fout, ret);

        } else {

            //C-instructionut
            c_instruction(str, ret);
            fprintf(fout, ret);
            
        }
    }

    fclose(fin);
    fclose(fout);
}