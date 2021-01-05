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
	struct Array * arr;
  	perf = newPerformance();
 	struct Car tesla, ford, ferrari, result;
 	if(perf == NULL){
 		printf("Performance is null, exiting\n");
 		return 0;
 	}
	arr = newArray(perf, sizeof(struct Car), 5);
	int arg1 = atoi(argv[1]);
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

 	contract(perf, arr);
 	if(arg1 == 1){
 		contract(perf, arr);
 	}
 	for (int i=0;i<arr->nel;i++){
    	readItem( perf, arr, i, &result );
	}
	printf("%d:%d\n",perf->reads, arr->nel);
	freeArray(perf, arr);
	free(perf);
	return 0;
}
