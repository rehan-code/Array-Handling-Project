#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	struct Performance *perf;
  	perf = newPerformance();
 	struct Array * arr;
 	int width = atoi(argv[1]);
 	int capacity = atoi(argv[2]);
 	if(perf == NULL){
 		printf("Perf is null, exiting\n");
 		return 0;
 	}
 	arr = newArray(perf, width, capacity);
 	if(arr == NULL){
 		printf("Not correct, array is equal to null\n");
 		return 0;
 	}
 	printf("%d %d %d\n", arr->width, arr->capacity, arr->nel);
 	freeArray(perf, arr);
 	free(perf);
	return 0;
}

