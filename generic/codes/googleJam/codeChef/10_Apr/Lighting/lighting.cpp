#include	<stdio.h>
#include	<string.h>
#include	<algorithm>

using namespace std;

int arr[701][700];
int arv[700];
int arc[700][700];
int tarc[700];
int arrow[700];

int current(0);
int UniqueNumber () { return ++current; }

int main(){
	int t, r, c, i, j, max, tmax, *rmax, k;
	char ch;
	scanf("%d", &t);
	while(t){
		memset(arr,0, sizeof(arr));
		memset(arv,0, sizeof(arv));
		memset(arc,1, sizeof(arc));
		scanf("%d %d", &r, &c);
		getchar();
		max = 0;
		for(i = 0; i < r; ++i){
			for(j = 0; j < c; ++j){
				ch = getchar();
				if((ch == '0') || (ch == '1'))
					arr[i][j] = ch - '0';
				else{
					--j;
					continue;
				}
				if(arr[i][j] == 1){
					++arr[r][j];
					++arv[i];
					if(arr[r][j] > max)
						max = arr[r][j];
					if(arv[i] > max)
						max = arv[i];
				}
			}
		}
		for(i = 0; i < r; ++i){
			current = 0;
			generate_n(arc[i], max, UniqueNumber);
		}
		printf("%d\n", max);
		++max;
		for(i = 0; i < r; ++i){
			current = 0;
			generate_n(arrow, max - 1, UniqueNumber);
			for(j = 0; j < c; ++j){
				if((arr[i][j]) == 1){
					for(k = 0; k < max; ++k){
						if(arc[j][k] < max){
							if(arrow[arc[j][k] - 1] < max){
								printf("%d ", arc[j][k]);
								arrow[arc[j][k] - 1] = max;
								arc[j][k] = max;
								break;
							}	
						}
					}
				}
				else
					printf("%d ", 0);
			}
			printf("\n");
		}
		printf("\n");
		--t;
	}
	return 0;
}
