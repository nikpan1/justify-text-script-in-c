#include <stdio.h>
#include <stdlib.h>


struct List {
	int size;
	int* container;
};


void freeList(struct List *list) {
	free(list->container);
}

void printList(struct List *list) {
	int index;
	for( index = 0; index <= list->size - 1; index ++) {
		printf("list[%d] = %d\n", index, list->container[index]);
	}

	printf("_________\n");
}

void clearList(struct List *list) {
	int listIndex;
	for(listIndex = 0; listIndex <= list->size - 1; listIndex ++) {
		list->container[listIndex] = 0;
	}
}

void setListSize(struct List *list, int listSize) {
	list->size = listSize;
}

void allocateList(struct List *list) {
	list->container = calloc(list->size, sizeof(int) );
}

void setList(struct List *list, int listSize) {
	setListSize(list, listSize);
	allocateList(list);
	clearList(list);
}

void reallocateList(struct List *list, int newSize) {
	int *newContainer;
	newContainer = calloc(newSize, sizeof(int));

    int counter = 0;
    for(counter = 0; counter <= newSize - 1; counter ++) {
        newContainer[counter] = list->container[counter]; 
    }

	list->size = newSize;
    *list->container = *newContainer;	// revealing!
	free(newContainer);
}

void appendToList(struct List *list, int number) {
	// without calloc -> appendToList won't work
	list->size ++;
	list->container = realloc(list->container, (list->size) * sizeof(int));
	list->container[list->size - 1] = number;
}

void removeListPosition(struct List *list, int index) {
	int listCounter;
	for(listCounter = index; listCounter <= list->size - 2; listCounter ++) {
		list->container[listCounter] = list->container[listCounter + 1];
	}
	
	reallocateList(list, list->size - 1);
}

int isListEmpty(struct List *list) {
	if(list->size == 0) {
		return 1;
	}
	
	return 0;
}
