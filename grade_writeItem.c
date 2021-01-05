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

void readFile( struct Performance *performance, struct Array *array )
{
  FILE *fp;
  struct Book book;
  int retval;

  fp = fopen( "../../../Graders/books.txt", "r" );

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
	int arg1 = atoi(argv[1]);
  	perf = newPerformance();
  	if(perf == NULL){
  		printf("Performance is null, exiting\n");
  		return 0;
  	}
 	struct Array * arr1, * arr2;
 	struct Car tesla, ford, ferrari;
	arr1 = newArray(perf, sizeof(struct Car), 5);
	if(arr1 == NULL){
		printf("Array 1 is null, exiting\n");
		free(perf);
		return 0;
	}
	strcpy(tesla.make, "tesla");
	strcpy(tesla.model, "s");
	strcpy(ford.make, "ford");
	strcpy(ford.model, "fusion");
	strcpy(ferrari.make, "ferrari");
	strcpy(ferrari.model, "laferrari");
	writeItem(perf, arr1, arr1->nel, &tesla);
	writeItem(perf, arr1, arr1->nel, &ford);
	writeItem(perf, arr1, arr1->nel, &ferrari);
 	if(arg1 == 1){
 		struct Car result;
 		for (int i=0;i<arr1->nel;i++){
    		readItem( perf, arr1, i, &result );
	  	}
 	} else {
 		struct Book resultb;
 		struct Car resultc;
	 	arr2 = newArray(perf, sizeof(struct Book), 50);
	 	if(arr2 == NULL){
	 		printf("Array 2 is null, exiting\n");
	 		freeArray(perf, arr1);
	 		free(perf);
	 		return 0;
	 	}
	 	readFile(perf, arr2);
 		readItem(perf, arr2, 15, &resultb);
 		readItem(perf, arr1, 0, &resultc);
 	}
	freeArray(perf, arr1);
	if(arg1 != 1){
		freeArray(perf, arr2);
	}
	printf("%d %d %d %d\n", perf->reads, perf->writes, perf->mallocs, perf->frees);
	free(perf);
	return 0;
}
