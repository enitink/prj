#include<stdio.h>
#include<string.h>

void print(int arr[])
{
	int i;
	for(i = 0; i < 52; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int t, res, arr[52], i;
	char ch;
	scanf("%d", &t);
	scanf("%c", &ch);
	while(t--)
	{
		res = 0;
		scanf("%c", &ch);
		memset(arr, 0, sizeof(arr));
		do
		{
			i = (ch - 'A');
			i = (i >= 32)? i - 6 : i;
			++arr[i];
			scanf("%c", &ch);			
		}while(ch != '\n');

		//print(arr);
		scanf("%c", &ch);

		do
		{
			i = (ch - 'A');
			i = (i >= 32)? i - 6 : i;
			if(arr[i])
			{
				++res;
			}
			scanf("%c", &ch);			
		}while(ch != '\n');
		//print(arr);
		printf("%d\n",res);
	}
	
	return 0;
}
