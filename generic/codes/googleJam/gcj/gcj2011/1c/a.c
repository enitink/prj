#include <stdio.h>
#include <string.h>
#include <math.h>

#define memsetZero(x)	memset(x, 0, sizeof(x))
#define memsetOne(x)	memset(x, 1, sizeof(x))
#define fol(x,y)	for(x = 0; x < y; ++x)
#define folR(x,y,z)	for(x = y; x < z; ++x)

#define RC	50

char mat[RC][RC], cht;

int main(){
	int i, t, r, c, j, k, ct, f;
	scanf("%d", &t);
	i = 1;

	while(t){
		memsetZero(mat);
		scanf("%d %d", &r, &c);
		fol(j,r)
			scanf("%s", mat[j]);
			
		fol(j, r){
			ct = 0;
			fol(k, c)
				if(mat[j][k] == '#')
					++ct;
			if(ct%2 != 0)
				break;
		}
					

		printf("Case #%d:\n", i++);

		if(ct%2 != 0)
			printf("Impossible\n");
		else{
			fol(j,r){
				f = 0;
				fol(k,c){
					if((mat[j][k] == '#') && (mat[j][k+1] == '#') && (mat[j+1][k] == '#') && (mat[j+1][k+1] == '#')){
						mat[j][k] = '/';
						mat[j][k+1] = '\\';
						mat[j+1][k] = '\\';
						mat[j+1][k+1] = '/';
						++k;					
					}
					else
					if((mat[j][k] == '.') || (mat[j][k] == '/') || (mat[j][k] == '\\'))
						continue;
					else{
						printf("Impossible\n", j , k);
						f = 1;
						break;
					}					
				}
				if(f)
					break;
			}
			if(!f){
				fol(j, r){
					fol(k, c)
						printf("%c", mat[j][k]);
					printf("\n");
				}	
			}
		}
		--t;
	}
	return t;
}
