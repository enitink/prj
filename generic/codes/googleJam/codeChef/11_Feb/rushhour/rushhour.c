#include <stdio.h>

int m,n,k;
char c[6][12];

int countSteps(int locR, locC){
	int s = 0;
	int hurdle[12];
	int i, j, k;

	if('a' == c[locR][locC]){
		s = 0;
		for(i = locC + 1; i < n; ++i){
			if('.' != c[locR][i]){
				hurdle[s] = i;
				++s;				
			}
		}
		for(i = 0; i < s; ++i){
			s += countSteps(locR, hurdle[i]};
		}
	}
	else{
		s = 0;
		if((c[locR][locC] == c[locR][locC + 1]) || (c[locR][locC] == c[locR][locC - 1])){
			s1 = 0;
			for(i = 0; i < locC; ++i){
				if('.' != c[locR][i]){
					hurdle[s1] = i;
					++s1;
				}
			}
			for(i = 0; i < s1; ++i){
				s1 += countSteps(locR, hurdle[i]);
			}
			s2 = 0;
			k = 0;
			while(c[locR][locC + k] == c[locR][locC]) ++k;

			for(i = loc + k; i < n; ++i){
				if('.' != c[locR][i]){
					hurdle[s2] = i;
					++s2;
				}
			}
			for(i = 0; i < s2; ++i){
				s2 += countSteps(locR, hurdle[i]);
			}
			if(s1 < s2)
				s = s1;
			else
				s = s2;
		}
		else{
			s1 = 0;
			for(i = 0; i < locR; ++i){
				if('.' != c[i][locC]){
					hurdle[s1] = i;
					++s1;
				}
			}
			for(i = 0; i < s1; ++i){
				s1 += countSteps(hurdle[i], locC);
			}
			s2 = 0;
			k = 0;
			while(c[locR][locC + k] == c[locR][locC]) ++k;

			for(i = loc + k; i < n; ++i){
				if('.' != c[locR][i]){
					hurdle[s2] = i;
					++s2;
				}
			}
			for(i = 0; i < s2; ++i){
				s2 += countSteps(hurdle[i], locC);
			}
			if(s1 < s2)
				s = s1;
			else
				s = s2;
		}			
	}

	if(0 == s)
		s = 1;
	return s;
}

int main(){
	int t;
	scanf("%d", &t);
	
	int i,j;
	int locR, locC;

	while(t){
		locR = locC = -1;
		scanf("%d %d %d", &m, &n, &k);
		for(i = 0; i < m; ++i)
			for(j = 0; j < n; ++j){
				scanf("%c", &c[i][j]);
				if('a' == c[i][j] && locR = -1){
					locR = i;
					locC = j + 1;
				}
			}
		printf("%d", countSteps(locR, locC);
		--t;
		if(t)
			printf("\n");
	}
}
