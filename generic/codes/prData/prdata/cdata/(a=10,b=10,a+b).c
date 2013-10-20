#include<stdio.h>

int main()
{
	int a,b,c;
	
	printf("\na=%d",a);
	printf("\nb=%d",b);
	printf("\nc=%d",c);
	
	c = (a=10, b=10, a+b);
	
	printf("\na=%d",a);
	printf("\nb=%d",b);
	printf("\nc=%d",c);
} 
