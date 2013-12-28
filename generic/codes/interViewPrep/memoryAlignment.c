#include <stdio.h>
#include <string.h>

typedef unsigned int u32_t;

int verify(char *p)
{
	char aData[10];
	short  aFlag = 0;

	strcpy(aData, p);

	printf("address : flag -> %x aData -> %x aData[0] -> %x aData[10] -> %x\n", (u32_t)&aFlag, (u32_t)aData, (u32_t)&aData[0], (u32_t)&aData[10]);
	printf("address : aData - flag -> %d aData[10] - aData[0] -> %d\n", (u32_t)aData - (u32_t)&aFlag, (u32_t)&aData[10] - (u32_t)&aData[0]);
	return aFlag;
}

int main(int argv, char** argc)
{
	printf("%d\n", verify(argc[1]));
	return 0;
}
