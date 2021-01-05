#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "array.h"

struct Car{
	char make[25];
	char model[25];
};

struct Book{
	char title[100];
	char author[100];
};

void readFile( struct Performance *performance, struct Array *array )
{
  FILE *fp;
  struct Book book;
  int retval;

  fp = fopen( "books.txt", "r" );

  while (!feof(fp))
  {
    // this scanf call is unsafe if inputs are wider the first or last strings
    retval = fscanf( fp, "%s %s", book.title, book.author );

    if (retval==2)
    {
      writeItem( performance, array, array->nel, &book );
    }
  }

  fclose( fp );
}

int main( int argc, char **argv )
{
	struct Performance *perf;
  	perf = newPerformance();
 	struct Array * arr;
  	if(perf == NULL){
  		printf("Performance is null, exiting\n");
  		return 0;
  	}
  	int arg1 = atoi(argv[1]);
 	if(arg1 == 1){
 		struct Car tesla, ford, ferrari, vw, result;
	 	arr = newArray(perf, sizeof(struct Car), 5);
	 	if(arr == NULL){
	 		printf("Array is null, exiting\n");
	 		free(perf);
	 		return 0;
	 	}
	 	strcpy(tesla.make, "tesla");
	 	strcpy(tesla.model, "s");
	 	strcpy(ford.make, "ford");
	 	strcpy(ford.model, "fusion");
	 	strcpy(ferrari.make, "ferrari");
	 	strcpy(ferrari.model, "laferrari");
	 	writeItem(perf, arr, arr->nel, &tesla);
	 	writeItem(perf, arr, arr->nel, &ford);
	 	writeItem(perf, arr, arr->nel, &ferrari);
	 	strcpy(vw.make, "vw");
	 	strcpy(vw.model, "golf");
	 	insertItem(perf, arr, 1, &vw);
	 	for(int i = 0; i < arr->nel; i++){
	 		readItem(perf, arr, i, &result);
	 	}
 		readItem(perf, arr, 1, &result);
 		printf("%s:%s:%d:%d\n", result.make, result.model, perf->reads, arr->nel);
 	} else {
 		struct Book tempbook, result;
	 	arr = newArray(perf, sizeof(struct Book), 50);
	 	if(arr == NULL){
	 		printf("Array is null, exiting\n");
	 		free(perf);
	 		return 0;
	 	}
	 	readFile(perf, arr);
 		strcpy(tempbook.title, "City-Of-Bones");
 		strcpy(tempbook.author, "Cassandra-Clare");
 		insertItem(perf, arr, 15, &tempbook);
 		for(int i = 0; i < arr->nel; i++){
	 		readItem(perf, arr, i, &result);
	 	}
 		readItem(perf, arr, 15, &result);
 		printf("%s:%s:%d:%d\n", result.title, result.author, perf->reads, arr->nel);
 	}
	freeArray(perf, arr);
	free(perf);
	return 0;
}
