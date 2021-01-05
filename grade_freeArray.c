#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Car{
	char make[25];
	char model[25];
};

int main( int argc, char **argv )
{
	struct Performance *perf;
	struct Car tesla, ford, ferrari;
  	perf = newPerformance();
  	if(perf == NULL){
  		printf("Performance is null, exiting\n");
  		return 0;
  	}
 	struct Array * arr;
 	arr = newArray(perf, sizeof(struct Car), 20);
 	if(arr == NULL){
 		printf("Array is null, exiting\n");
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

	freeArray(perf, arr);
	printf("%d\n", perf->frees);
	free(perf);
	return 0;
}

