#include "array.h"
/**
 *  File Name: bandb.c
 *  Author: Rehan Nagoor Mohideen
 *  Student ID: 1100592
 *  Purpose: Contain functions for 2520 assignment 2
 */

struct Performance *newPerformance() {
    struct Performance *new_performance = malloc(sizeof(struct Performance));//allocate memory to the structure
    if (new_performance == NULL) { //For error handling
        fprintf(stderr, "error: not enough space for mallocof newPerformance\n");
        exit(0);
    }
    //initialize values to 0
    new_performance->reads = 0;
    new_performance->writes = 0;
    new_performance->mallocs = 0;
    new_performance->frees = 0;

    return new_performance;
}

struct Array *newArray(struct Performance *performance, unsigned int width, unsigned int capacity ) {
    struct Array *new_Array = malloc(sizeof(struct Array));//allocate memory to the structure
    if (new_Array == NULL) { //For error handling
        fprintf(stderr, "ERROR: not enough space for malloc of newArray.\n");
        exit(0);
    }
    //initialize values
    new_Array->width = width;
    new_Array->capacity = capacity;
    new_Array->nel = 0;
    new_Array->data = malloc(width*capacity);//allocate memory to data
    if (new_Array->data == NULL) { //For error handling
        fprintf(stderr, "ERROR: not enough space for malloc of newArray->data.\n");
        exit(0);
    }

    performance->mallocs++;

    return new_Array;
}

void readItem( struct Performance *performance, struct Array *array, unsigned int index, void *dest ) {
    if (index >= array->nel) {//For error handling
        fprintf(stderr, "ERROR: index value >= no. of elements in the array to read from.\n");
        exit(0);
    } else {
        unsigned char *ptr = array->data;
        memcpy(dest, ptr + (index * array->width), array->width);//copies data to destination

        performance->reads++;
    }
}

void writeItem( struct Performance *performance, struct Array *array, unsigned int index, void *src ) {
    if (index > array->nel || index >= array->capacity) {//For error handling
        fprintf(stderr, "ERROR: index value exceeds the no. of elements in the array or the exceeds or equals the the array capacity\n");
        exit(0);
    } else {
        unsigned char *ptr = array->data;
        memcpy(ptr + (index * array->width), src, array->width);//copies data from source into the appropriate palce in the array

        if (index == array->nel) {//if its adding a new item to the array then, increase the no. of elements in the array.
            array->nel++;
        }
        
        performance->writes++;
    }
}

void contract( struct Performance *performance, struct Array *array ) {
    if (array->nel == 0) {//for error handling
        fprintf(stderr, "ERROR: array is empty. cannot contract\n");
        exit(0);
    } else {//otherwise decrement the nel
        array->nel--;
    } 
}

void freeArray( struct Performance *performance, struct Array *array ) {
    free(array->data);
    free(array);
    performance->frees++;
}

void appendItem( struct Performance *performance, struct Array *array, void *src ) {
    writeItem(performance, array, array->nel, src);//adding an item to the end of the array
}

void insertItem( struct Performance *performance, struct Array *array, unsigned int index, void *src ) {
    int i;
    unsigned char *ptr = array->data;
    //going from the last element up to the index element to move them forward to make space to insert a value in the array
    // for (i = array->nel; i > index; i--) {
    //    writeItem(performance, array, i, ptr + ((i-1) * array->width));//move the value at the index one value to the next
    // }
    
    // change for regrade
    writeItem(performance, array, array->nel, ptr + ((array->nel-1) * array->width));
    for (i = (array->nel-1); i > index; i--) {
       readItem(performance, array, i-1, ptr + ((i) * array->width));//move the value at the index one value to the next
    }

    writeItem(performance, array, index, src);//inserting the new element into the array position
}

void prependItem( struct Performance *performance, struct Array *array, void *src ) {
    insertItem(performance, array, 0, src);//insert an tiem to the start of the array
}

void deleteItem( struct Performance *performance, struct Array *array, unsigned int index ) {
    int i;
    unsigned char *ptr = array->data;
    for (i = index; i < array->nel-1; i++) {//from the index element till the second to last element in the array
        readItem(performance, array, i+1, ptr + ((i) * array->width));//shift the array values up by one
    }
    contract(performance, array);// delete the extra copy in the end.
}

int findItem( struct Performance *performance, struct Array *array, int (*compar)(const void *, const void *), void *target ) {
    int i;
    void *dest = malloc(array->width);//to store the value at the index position
    for (i = 0; i < array->nel; i++) {
        readItem(performance, array, i, dest);
        if (compar(target, dest) == 0) { // check if there is match to return the index
            free(dest);
            return i;
        }
    }

    free(dest);
    return -1;//If it goes through the entire array without a match returns -1 (no match)
}

int searchItem( struct Performance *performance, struct Array *array, int (*compar)(const void *, const void *), void *target ) {
    int middle = 0;
    int lb = 0;
    int ub = array->nel-1;
    void *dest = malloc(array->width);//to store the value at the index position
    int result;

    while (ub >= lb) {//while it is within the array
        middle = (ub + lb) / 2;// find the middle index
        readItem(performance, array, middle, dest);// get the address of the value at that location
        result = compar(dest, target);//compare the values and get the result
        if (result > 0) {//if the result is greater then the value is in the upper portion
            ub = middle - 1;
        } else if (result < 0) {//if the result is lower then the value is the lower portion
            lb = middle + 1;
        } else {//if the values are equal return the index of the value
            free(dest);
            return middle;
        }
    }
    
    free(dest);
    return -1;//return -1 to indicate no matches in the array
}