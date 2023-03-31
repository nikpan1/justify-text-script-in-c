#include <stdio.h>
#include <stdlib.h>


void handleArgc(int *argc) {
    if(*argc != 3) {
        /* .\main3 - argc[0]*/
        printf("Error - programm needs exactly 2 input parameters.\n");
        exit(1);
    }
}

int toInt(char *arg) {
	int convertedNumber;
	if((sscanf(arg,"%d",&convertedNumber) == 0)) {
		printf("Error - bad argument\n");
	}
	return convertedNumber;
}

FILE* openFile(char *PATH, char *option) {
	FILE* file;
	if((file = fopen(PATH, option)) == NULL){
		printf("Error - file not found.\n");
    	exit(1);	
    }
    return file;
}

void saveToFile(FILE *file, struct Array *output) {
	if ((fprintf(file,"%s\n", output->container)) == 1) {
		printf("Error - line was not saved.\n");
		exit(1);
	}
}
