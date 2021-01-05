#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	struct Performance *perf;
  	perf = newPerformance();
 
	if(perf != NULL && perf->reads == 0 && perf->writes == 0 && perf->mallocs == 0 && perf->frees == 0){
		printf("CORRECT\n");
	} else {
		printf("INCORRECT\n");
	}
	if(perf != NULL){
		free(perf);
	}
	return 0;
}

