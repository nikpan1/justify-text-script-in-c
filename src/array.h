#include <stdio.h>
#include <stdlib.h>


struct Array {
	int size;
	char* container;
};


void freeArray(struct Array *array) {
	free(array->container);
}

int getLength(struct Array *array) {
	int index, wordCounter;
	wordCounter = 0;
	for(index = 0; index <= array->size - 1; index ++) {
		if(array->container[index] != '\0' /* != NULL */) {
			wordCounter ++;
		}
	}
	return wordCounter;
}

void clearArray(struct Array *array) {
	int arrayIndex;
	for(arrayIndex = 0; arrayIndex <= array->size - 1; arrayIndex ++) {
		array->container[arrayIndex] = '\0' /* = NULL */;
	}
}

void setArraySize(struct Array *array, int arraySize) {
	array->size = arraySize;
}

void allocateArray(struct Array *array) {
	array->container = calloc(array->size, sizeof(char) );
}

void setArray(struct Array *array, int arraySize) {
	setArraySize(array, arraySize);
	allocateArray(array);
	clearArray(array);
}

void sizeErrorHandling(struct Array *firstArray, struct Array *secondArray) {
	if (firstArray->size < getLength(firstArray) + getLength(secondArray)) {
		printf("Error - array to small");
		exit(1);
	}
}

void appendToArray(struct Array *appendedArray, struct Array *addend) {
	sizeErrorHandling(appendedArray, addend);

	int addIndex = 0;
	int appendedLen = getLength(appendedArray);
	int addendLen = getLength(addend);
	
	for(addIndex = 0; addIndex <= addendLen; addIndex ++) {
		if (appendedArray->container[appendedLen + addIndex] != '\0') {
			printf("Error - overwriting");
			exit(1);
		}
		else {
		appendedArray->container[appendedLen + addIndex] = addend->container[addIndex];
		}
	}
}
 
int isArrayFull(struct Array *array) {
	if(array->size == getLength(array)) {
		printf("Error - array is full\n");
		return 1;
	}
	return 0;
}

int isArrayEmpty(struct Array *array) {
	if(getLength(array) == 0) {
		return 1;
	}
	
	return 0;
}

void removeArrayPosition(struct Array *array, int index) {
	int counter;
	int buffer = getLength(array) - 1;
	for(counter = index; counter <= array->size - 2; counter ++) {
		array->container[counter] = array->container[counter + 1];
	}
	array->container[buffer] = '\0';
}
