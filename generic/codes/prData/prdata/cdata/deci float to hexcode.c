#include<stdio.h>

void main() 
{
	float a = 16;
	char *p;
	int i;
	p = (char*) &a;
	for(i = 0; i<=3; i++)
		printf(" %02x ",(unsigned char)p[i]);
	printf("\n");
}

