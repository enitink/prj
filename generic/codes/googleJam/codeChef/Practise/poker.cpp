#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

#include	<cstring>

//#include	<algorithm>
#include	<numeric>
using std::accumulate;

bool arr[4][13];
int hor;
int vert[13];
enum cards{Ace = 0, Ten = 9, Jack = 10, Queen = 11, King = 12};
enum suits{D,H,C,S};

int acc(int i){
	
}

void find_hand(){
	int i, j;
	for(i = 0; i < 4; ++i){
		hor = accumulate(&arr[i][0],&arr[i][13], 0);
		if(hor == 5){
			if((arr[i][0] + accumulate(&arr[i][9], &arr[i][13], 0)) == 5){
				cout << "royal flush" << endl;
				return;
			}
			for(j = 0; j <= 8; ++j){
				if(accumulate(&arr[i][j], &arr[i][j + 5], 0) == 5){
					cout << "straight flush" << endl;
					return;
				}
			}
			cout << "flush" << endl;
			return;
		}			
	}
	memset(vert,0,sizeof(vert));
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 13; ++j)
			cout << " " << arr[i][j];
		cout << endl;
	}
	for(i = 0; i < 13; ++i){
		vert[i] = acc(i);
		cout << endl << "vert = " << vert[i];
		if(i >= 4)
			if((accumulate(&vert[i - 5], &vert[i], 0)) == 5)
				cout << "straight";
	}
	cout << "high card" << endl;
}
int main(){
	int tests, i,j,r,c;
	char rank, suit ;
	cin >> tests;
	while(tests){
		memset(arr,0,sizeof(arr));
		for(i = 0; i < 5; ++i){
			cin >> rank >> suit;
			switch (rank){
			case 'A':
				c = Ace;
				break;
			case 'T':
				c = Ten;
				break;
			case 'J':
				c = Jack;
				break;
			case 'Q':
				c = Queen;
				break;
			case 'K':
				c = King;
				break;
			default:
				c = rank - '0' - 1;
			}
			switch (suit){
			case 'D':
				r = D;
				break;
			case 'H':
				r = H;
				break;
			case 'C':
				r = C;
				break;
			case 'S':
				r = S;
				break;
			}
			arr[r][c] = true;
		}
		find_hand();
		--tests;
	}
	return 0;
}
