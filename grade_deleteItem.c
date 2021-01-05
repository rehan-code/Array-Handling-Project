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
  	perf = newPerformance();
 	struct Array * arr;
  	int tempnel = 0;
  	int matchingval = 0;
 	if( atoi(argv[1]) == 1){
 		struct Car tesla, ford, ferrari, vw, oneup, result;
	 	arr = newArray(perf, sizeof(struct Car), 5);
	 	strcpy(tesla.make, "tesla");
	 	strcpy(tesla.model, "s");
	 	strcpy(ford.make, "ford");
	 	strcpy(ford.model, "fusion");
	 	strcpy(ferrari.make, "ferrari");
	 	strcpy(ferrari.model, "laferrari");
	 	strcpy(vw.make, "vw");
	 	strcpy(vw.model, "golf");
	 	writeItem(perf, arr, arr->nel, &tesla);
	 	writeItem(perf, arr, arr->nel, &ford);
	 	writeItem(perf, arr, arr->nel, &ferrari);
	 	writeItem(perf, arr, arr->nel, &vw);
	 	tempnel = arr->nel;
	 	readItem(perf, arr, 2, &oneup);
	 	deleteItem(perf, arr, 1);
	 	readItem(perf, arr, 1, &result);
	 	//for(int i = 0; i < arr->nel; i++){
	 	//	readItem(perf, arr, i, &result);
	 	//}
	 	if(strcmp(oneup.make, result.make) == 0 && strcmp(oneup.model, result.model) == 0){
	 		matchingval = 1;
	 	}
 		readItem(perf, arr, 1, &result);
 		printf("%d:%d", matchingval, tempnel - arr->nel);
 	} else {
 		struct Book tempbook, oneup, result;
	 	arr = newArray(perf, sizeof(struct Book), 50);
		readFile( perf, arr );

 		strcpy(tempbook.title,"City-Of-Bones");
 		strcpy(tempbook.author,"Cassandra-Clare");
	 	tempnel = arr->nel;
 		readItem(perf, arr, 16, &oneup);
 		deleteItem(perf, arr, 15);
 		readItem(perf, arr, 15, &result);
 		//for(int i = 0; i < arr->nel; i++){
	 	//	readItem(perf, arr, i, &result);
	 	//}
	 	if(strcmp(oneup.title, result.title) == 0 && strcmp(oneup.author, result.author) == 0){
	 		matchingval = 1;
	 	}
 		printf("%d:%d", matchingval, tempnel - arr->nel);
 	}
	freeArray(perf, arr);
	free(perf);
	return 0;
}
