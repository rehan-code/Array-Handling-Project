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
 	int arg1 = atoi(argv[1]);
 	if(perf == NULL){
	 		printf("Performance is null exiting\n");
 			return 0;
	}
 	if(arg1 == 1){
 		struct Car tesla, ford, ferrari, result;
	 	arr = newArray(perf, sizeof(struct Car), 5);
	 	if(arr == NULL){
	 		printf("Array is null exiting\n");
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
 		readItem(perf, arr, 1, &result);
 		printf("%s:%s:%d:%d\n", result.make, result.model, perf->reads, perf->writes);
 	} else {
 		struct Book result;
	 	arr = newArray(perf, sizeof(struct Book), 50);
	 	if(arr == NULL){
	 		printf("Array is null exiting\n");
 			return 0;
	 	}
 		readFile(perf, arr);
 		readItem(perf, arr, 21, &result);
 		printf("%s:%s:%d:%d\n", result.title, result.author, perf->reads, perf->writes);
 	}
	freeArray(perf, arr);
	free(perf);
	return 0;
}
