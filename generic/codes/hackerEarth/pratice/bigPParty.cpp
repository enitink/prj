#include <cstdio>
#include <algorithm>
#include <cstring>

#define SIZE 500000 
#define IF_SWAP(X,Y) if( Y < X ){ X = X ^ Y; Y = X ^ Y; X = X ^ Y; }

typedef struct
{
	int r;
	int c;
}loc_s;

using namespace std;

bool searchfunction(loc_s a, int b)
{
	if ( a.r < b)
		return true;
	return false;
}

bool myfunction (loc_s a,loc_s b)
{
	if (a.r < b.r)
		return true;
	if (a.r > b.r)
		return false;
	if (a.c < b.c)
		return true;
	return false; 
}

void calcRes(loc_s* arr, int* res, int b)
{
	int i = 0;
	int temp = arr[i].r;
	loc_s* p;
	while ( arr[i].r == temp )
	{
		if(arr[i].r == 0 )
			res[arr[i].c] = 1;
		else if ( res[arr[i].c] == 0 )
			res[arr[i].c] = res[arr[i].r] + 1;
		else if ( res[arr[i].c] != 0 )
			res[arr[i].c] =  (res[arr[i].c] < res[arr[i].r] + 1) ? res[arr[i].c] : res[arr[i].r] + 1;
		if ( res[arr[i].r] == 0 )
			res[arr[i].r] = res[arr[i].c] + 1;
		else if ( res[arr[i].r] != 0 )
			res[arr[i].r] =  (res[arr[i].r] < res[arr[i].c] + 1) ? res[arr[i].r] : res[arr[i].c] + 1;

		p = lower_bound(arr, arr + b, arr[i].c, searchfunction);
		if ( p != arr + b )
		{
			calcRes(p, res, b - ( p - arr ));
		}
		++i;
	}
}

int main()
{
	int a,b,i;
	loc_s arr[SIZE];
	int res[SIZE];

	scanf("%d%d",&a,&b);
	for(i = 0; i < b; ++i)
	{
		scanf("%d%d", &arr[i].r, &arr[i].c);
		IF_SWAP(arr[i].r, arr[i].c);
	}
	sort(arr, arr + b, myfunction);
	memset(res, 0, sizeof(res));
//	for(i = 0; i < b; ++i)
//		printf("%d %d\n", arr[i].r, arr[i].c);
	if( arr[i].r == 0 )
		calcRes(arr, res, b);
	for(i = 1; i < a; ++i)
	{
		printf("%d\n", res[i] ? res[i] : -1);
	}
	return 0;
}
