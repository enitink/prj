#include<stdio.h>

void fn(int a, int b)
{
	printf("\nFn : a = %d \t b = %d", a, b);
} 

int main()
{
	int a = 5;
	
	printf("\nMain : %d  %d", a++, ++a);
	
	printf("\nvalue of a =  %d", a);
	
	fn(a, ++a);
	
	return 0;
}