#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Car{
	char make[25];
	char model[25];
};

struct Book{
	char title[100];
	char author[100];
};

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
 	int tempnel = 0;
 	if(arg1 == 1){
 		struct Car tesla, ford, ferrari, vw, result;
	 	arr = newArray(perf, sizeof(struct Car), 5);
	 	if (arr == NULL){
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
	 	tempnel = arr->nel;
	 	appendItem(perf, arr, &vw);
	 	for(int i = 0; i < arr->nel; i++){
	 		readItem(perf, arr, i, &result);
	 	}
 		readItem(perf, arr, (arr->nel)-1, &result);
 		printf("%s:%s:%d:%d\n", result.make, result.model, perf->reads, (arr->nel - tempnel));
 	} else {
 		struct Book tempbook, result;
	 	arr = newArray(perf, sizeof(struct Book), 50);
	 	if (arr == NULL){
	 		printf("Array is null, exiting\n");
	 		free(perf);
	 		return 0;
	 	}
 		strcpy(tempbook.title, "City-Of-Bones");
 		strcpy(tempbook.author, "Cassandra-Clare");
 		tempnel = arr->nel;
 		appendItem(perf, arr, &tempbook);
 		for(int i = 0; i < arr->nel; i++){
	 		readItem(perf, arr, i, &result);
	 	}
 		readItem(perf, arr, (arr->nel)-1, &result);
 		printf("%s:%s:%d:%d\n", result.title, result.author, perf->reads, (arr->nel - tempnel));
 	}
	freeArray(perf, arr);
	free(perf);
	return 0;
}
