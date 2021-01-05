#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRLEN    100

int cmp2( const void *v1, const void *v2 )
{
  const char *s1, *s2;

  s1 = v1;
  s2 = v2;

  // printf( "cmp(\"%s\",\"%s\")=%d\n", s1, s2, strcmp(s1,s2) );
  return strcmp(s1,s2);
}

void readFile( struct Performance *performance, struct Array *array )
{
  FILE *fp;
  char book[STRLEN];
  char * retval;

  fp = fopen( "../../../Graders/books.txt", "r" );

  while (!feof(fp))
  {
    // this scanf call is unsafe if inputs are wider the first or last strings
    retval = fgets(book, STRLEN, fp);

    if (retval!=NULL)
    {
      book[strlen(book)-2] = '\0';
      writeItem( performance, array, array->nel, &book );
    }
  }

  fclose( fp );
}

int main( int argc, char **argv )
{
  struct Performance *perf;
    perf = newPerformance();
    if(perf == NULL){
      printf("Performance is null, exiting\n");
      return 0;
    }
  struct Array * arr;
    int fnd = 0;
    char search[100];
    char result[100];
  int arg1 = atoi(argv[1]);
  int correct = 0;
  if(arg1 == 1){
    char car[100];
    arr = newArray(perf, STRLEN, 5);
    if(arr == NULL){
      printf("Array is null, exiting\n");
      free(perf);
      return 0;
    }
    strcpy(car, "ferrari laferrari");
    writeItem(perf, arr, arr->nel, &car);
    strcpy(car, "ford fusion");
    writeItem(perf, arr, arr->nel, &car);
    strcpy(search, "rimac c1");
    writeItem(perf, arr, arr->nel, &car);
    strcpy(car, "tesla s");
      fnd = searchItem( perf, arr, &cmp2, search );
      if(fnd == -1){
        correct = 1;
      }
      strcpy(search, "ferrari laferrari");
      if(fnd != -1){
      readItem(perf, arr, fnd, result);
        if(cmp2(result, search) == 0){
          ++correct;
        }
      }
  } else {
    arr = newArray(perf, STRLEN, 50);
    readFile(perf, arr);
    if(arr == NULL){
      printf("Array is null, exiting\n");
      free(perf);
      return 0;
    }
    char * test_books[6] = { "Dead-Souls Nikolai-Gogol",
                         "Anna-Karenina Leo-Tolstoy",
                         "Crime-and-Punishment Fyodor-M-Dostoyevsky",
       "The-Castle Franz-Kafka",
       "The-Devil-to-Pay-in-the-Backlands Joao-Guimaraes-Rosa",
       "City-Of-Bones Cassandra-Clare" };
    
    for(int i = 0; i < 6; i++){
        fnd = searchItem( perf, arr, &cmp2, test_books[i] );
        if(fnd != -1){
          readItem(perf, arr, fnd, result);
          if(cmp2(result, test_books[i]) == 0){
            ++correct;
          }
        }
        if(i == 5 && fnd == -1){
          ++correct; 
        }
    }
  }
  printf("%d:%d\n", correct,perf->reads<40); // be a bit generous
  freeArray(perf, arr);
  free(perf);
  return 0;
}
