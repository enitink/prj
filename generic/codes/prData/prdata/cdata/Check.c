#include<stdio.h>

void Qu74_2006()
{
	int a,b, *p1, *p2, y;
	a = 3; b = 4; p1=&a; p2=&b;
	y=4*-(*p2)/(*p1)+10;
	a*=b*=a*=y;
	printf("%d,%d,%d\n",y,a,b);
}

void Qu72_2006()
{
	char p;
	if((p = getchar())!='\n') Qu72_2006();
	putchar(p);
	return;
}

int Qu69_2006(int p)
{
	static int x = 10;
	if(x == 1) return 1;
	if(x > 0)
	{
		x--;
		return p*Qu69_2006(p);
	}
}

void Qu66_2006()
{
	char a[] = "Computation";
	char *p = a, b=' ';
	int i;
	
	for(i = 1; i < 12; i++)
		if(i%4) continue;
		else a[i]=b;
	puts(p);	
}

void Qu64_2006()
{
	int a = 256, *p=&a;
	printf("%d",*p>>5);
}

void Qu62_2006()
{
	int a = 10, b = 4;
	
	if(a&1 || b&1)
		printf("\nHello");
	else
		printf("\nWelcome");
}

void Qu60_2006()
{
	int a[]={2,3,4,5,6};
	int *p = a, i;
	for(i = 0; i < 5; i++)
		printf("%d",++*p);
}

void main()
{
	printf("\nQu74_2006 : ");
	Qu74_2006();
	printf("\nQu72_2006 : ");
	Qu72_2006();
	printf("\nQu69_2006 :");
	printf("%d", Qu69_2006(2));
	printf("\nQu66_2006 : ");
	Qu66_2006();
	printf("\nQu64_2006 : ");
	Qu64_2006();
	printf("\nQu62_2006 : ");
	Qu62_2006();
	printf("\nQu60_2006 : ");
	Qu60_2006();
	printf("\n");
} 

