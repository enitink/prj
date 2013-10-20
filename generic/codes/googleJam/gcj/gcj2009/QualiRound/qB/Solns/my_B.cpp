#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cstring>

#define		MAX_H		100
#define		MAX_W		100
#define		MAX_DATA	100001
int	W, H;

int	MapArr[MAX_H][MAX_W];
char	BasinArr[MAX_H][MAX_W];
char	ch;
int	MinCheckArr[4];

int FindMin(){
	int min = 0;
	for(int i = 1; i < 4; ++i){
		if(MinCheckArr[i] < MinCheckArr[min])
			min = i;
	}
	return min;
}

char AssignBasin(int j, int k){
	if((BasinArr[j][k] >= 'a') && (BasinArr[j][k] <= 'z')){
		return BasinArr[j][k];
	}
	else{
		int min = -1;
		MinCheckArr[0] = (j > 0) ? MapArr[j-1][k] : MAX_DATA;
		MinCheckArr[1] = (k > 0) ? MapArr[j][k-1] : MAX_DATA;
		MinCheckArr[2] = (k < W - 1)? MapArr[j][k+1] : MAX_DATA;
		MinCheckArr[3] = (j < H - 1)? MapArr[j+1][k] : MAX_DATA;
		min = FindMin();
		if(MinCheckArr[min] == MapArr[j][k]){
			BasinArr[j][k] = ch;
			++ch;
			return BasinArr[j][k];
		}
		if(MinCheckArr[min] > MapArr[j][k]){
			if((BasinArr[j][k] >= 'a') && (BasinArr[j][k] <= 'z')){
				return BasinArr[j][k];
			}
			else{
				BasinArr[j][k] = ch;
				++ch;
				return BasinArr[j][k];
			}
		}
		else{
			switch (min) {
			case	0:
				BasinArr[j][k] = ch;
				BasinArr[j][k] = AssignBasin(j-1,k);
				break;
			case	1:
				BasinArr[j][k] = AssignBasin(j,k-1);
				break;
			case	2:
				BasinArr[j][k] = AssignBasin(j,k+1);
				break;
			case	3:
				BasinArr[j][k] = AssignBasin(j+1,k);
				break;
			}
			return BasinArr[j][k];			
		}
	}
}

int main(){
	int T, i, j, k;
	cin >> T;
	
	for(i = 0; i < T; ++i){
		cin >> H >> W;
		for(j = 0; j < H; ++j){
			for(k = 0; k < W; ++k){
				cin >> MapArr[j][k];
			}
		}
		memset(BasinArr, 0, MAX_H * MAX_W * sizeof(char));
		ch = 'a';
		for(j = 0; j < H; ++j){
			for(k = 0; k < W; ++k){
				if((BasinArr[j][k] >= 'a') && (BasinArr[j][k] <= 'z'))
					continue;
				else{
					AssignBasin(j,k);
				}
			}
		}
		cout << "Case #" << i + 1 <<  ":" << endl;
		for(j = 0; j < H; ++j){
			for(k = 0; k < W - 1; ++k){
				cout << BasinArr[j][k] << " ";
			}
			cout << BasinArr[j][k];
			cout << endl;
		}
	}
}
