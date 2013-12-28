#include<stdio.h>


int main(){
	int * ptr = 0;
	char * chptr = 0;
	float * fpptr = 0;
	double * dbptr = 0;

	printf("%d", (int) ++ptr - 0);
	printf("\n%d", (int) ++chptr - 0);
	printf("\n%d", (int) ++fpptr - 0);
	printf("\n%d", (int) ++dbptr - 0);

	return 0;
}
