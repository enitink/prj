#include <stdio.h>
#include <unistd.h>

int global;

int main(char *argV[], int argC){
	int local;

	printf("Address of global %X\n", &global);
	printf("Address of main %X\n", main);
	printf("Address of argC %X\n", &argC);
	printf("Address of argV %X\n", argV);
	printf("Address of local %X\n", &local);
	printf("Address of printf %X\n", printf);
	printf("Address of fork %X\n", fork);

	return 0;
}
