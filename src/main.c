#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "list.h"
#include "IOandErrorHandling.h"


int getWordFromFile(FILE *fileInput, struct Array *word) {
	if(fscanf(fileInput, " %s", word->container) != 1) {
		return 0;
	}

	return 1;
}

void handleBadLineLimit(int length, int lineLimit) {
	if(length > lineLimit) {
		printf("Error - the lineLimit is to small.\n");
		exit(1);
	}
}

struct List findAll(struct Array *array) {
	int element;
	struct List foundList;
    setList(&foundList, 0);		

	for(element = 0; element <= array->size - 1; element ++) {
		if(array->container[element] == ' ') {
            appendToList(&foundList, element);
		}
	}

	return foundList;
}

void insertSpace(struct Array *array, int pasteMarker){
	if(isArrayFull(array)) {
		printf("Error - oversized\n");
		exit(1);
	}

	int index;
	for(index = getLength(array); index >= pasteMarker; index --) {
		array->container[index] = array->container[index - 1];
	}
	array->container[pasteMarker] = ' ';
}

void incrementList(struct List *list, int begin) {
	int index;
	for(index = begin + 1; index <= list->size - 1; index ++) {
		list->container[index] ++;
	}
}

void removeSpaceFromEnd(struct Array *array){
	int index = getLength(array) - 1;

    while(array->container[index] == ' ') {
        array->container[index] = '\0';
        index --;
    }
}

void appendSpaceToArray(struct Array *array) {
	if(isArrayFull(array)) {
		printf("Error - cannot append Space to array\n");
	}

	array->container[getLength(array)] = ' ';
}

void justify(struct Array *line) {
	int lineLimit = line->size;
	struct List positionList = findAll(line);
	int middleIndex = 0;

	while(getLength(line) != lineLimit) {
		if(isListEmpty(&positionList)) {
            positionList = findAll(line);
		}

		middleIndex = (int) positionList.size / 2;

    	insertSpace(line, positionList.container[middleIndex]);
		incrementList(&positionList, middleIndex);
		removeListPosition(&positionList, middleIndex);
	}

	freeList(&positionList);
}


void main(int argc, char** argv) {
    handleArgc(&argc);
	int lineLimit = toInt(argv[1]);

	int totalLength = 0;
	struct Array wordFromFile, lineBuffer;
	setArray(&wordFromFile, 100);		// The longest word can be -lineLimit- long.
	setArray(&lineBuffer, lineLimit);

	FILE *fileInput = openFile(argv[2], "r");  
	FILE *fileOutput = openFile("output.txt", "w");


    while(getWordFromFile(fileInput, &wordFromFile)) {
		handleBadLineLimit(getLength(&wordFromFile), lineLimit);
		totalLength = getLength(&wordFromFile) + getLength(&lineBuffer);

		if(totalLength >= lineLimit) {
			
			removeSpaceFromEnd(&lineBuffer);
			justify(&lineBuffer);
			saveToFile(fileOutput, &lineBuffer);
			clearArray(&lineBuffer);
		}
		else {
			appendToArray(&lineBuffer, &wordFromFile);
			appendSpaceToArray(&lineBuffer);
		}
		
		clearArray(&wordFromFile);
	}

	// last line without justify()
	saveToFile(fileOutput, &lineBuffer);

	fclose(fileInput);
	fclose(fileOutput);
	freeArray(&lineBuffer);
	freeArray(&wordFromFile);

	printf("\nDone!\n");
	exit(0);
}
