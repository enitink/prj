#include	<cstdio>
#include	<algorithm>
#include	<cstring>

#define		MAXN	2000

using namespace std;

struct Data{
	int data[4];
};

struct Data arr[MAXN][MAXN];
int arrin[MAXN][MAXN], n;

int hori(int i, int j, int c = 0){
	if(j >= n)
		return c;
	if(arrin[i][j] == 0)
		return c;
	else
		arr[i][j].data[0] = hori(i, j + 1, c + 1);
}

int verti(int i, int j, int c = 0){
	if(i >= n)
		return c;
	if(arrin[i][j] == 0)
		return c;
	else
		arr[i][j].data[1] = verti(i + 1, j, c + 1);
}

int diagr(int i, int j, int c = 0){
	if( (j >= n) || (i >= n) )
		return c;
	if(arrin[i][j] == 0)
		return c;
	else
		arr[i][j].data[2] = diagr(i + 1, j + 1, c + 1);
}

int diagl(int i, int j, int c = 0){
	if( (j < 0) || (i >= n) )
		return c;
	if(arrin[i][j] == 0)
		return c;
	else
		arr[i][j].data[3] = diagl(i + 1, j - 1, c + 1);
}

int main(){
	int i, j;
	scanf("%d", &n);
	char ch;
	ch = getchar();
	memset(arrin, 0, sizeof(arrin));
	for(i = 0; i < n; ++i){
		j = 0;
		while( (ch = getchar()) != '\n' ){
			if('X' == ch){
				arrin[i][j] = 1;
				++j;
			}
			else{
				if('.' == ch)
					++j;
			}
			arr[i][j].data[0] = 0;
			arr[i][j].data[1] = 0;
			arr[i][j].data[2] = 0;
			arr[i][j].data[3] = 0;
		}
	}
	for(i = 0; i < n; ++i){
		for(j = 0; j <n; ++j){
			if( 1 == arrin[i][j] ){
				if( 0 == arr[i][j].data[0] ){
					hori(i,j);
				}
				if( 0 == arr[i][j].data[1] ){
					verti(i,j);
				}
				if( 0 == arr[i][j].data[2] ){
					diagr(i,j);
				}
				if( 0 == arr[i][j].data[3] ){
					diagl(i,j);
				}
			}
//			printf("%d%s", *max_element(&arr[i][j].data[0], &arr[i][j].data[4]), (j < n - 1)? " " : "\n");
			printf("%d ", *max_element(&arr[i][j].data[0], &arr[i][j].data[4]));
		}
		printf("\n");
	}
	return 0;
}
