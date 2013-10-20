#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cmath>

#include	<cstring>

#include	<iomanip>

using std::setprecision;
using std::fixed;

#define		Distance(X1,Y1,X2,Y2)		sqrt(((X1 - X2) * (X1 - X2)) + ((Y1 - Y2) * (Y1 - Y2)))
#define		SIZE				100001

int 		arr[SIZE][2];

int main(){
	int cases, i, tests, j;
	float distance;
	bool flag;
	cin >> cases;
	while(cases){
		cin >> tests;
		memset(arr, 0, sizeof(arr));
		for(i = 0; i < tests; ++i)
			cin >> arr[i][0] >> arr[i][1];
		for(j = 0; j < tests; ++j){
			flag = false;
			for(i = 0; i < tests - j - 1; ++i){
				if(arr[i][0] > arr[i + 1][0]){
					arr[i][0] = arr[i][0] ^ arr[i + 1][0];
					arr[i + 1][0] = arr[i][0] ^ arr[i + 1][0];
					arr[i][0] = arr[i][0] ^ arr[i + 1][0];
					arr[i][1] = arr[i][1] ^ arr[i + 1][1];
					arr[i + 1][1] = arr[i][1] ^ arr[i + 1][1];
					arr[i][1] = arr[i][1] ^ arr[i + 1][1];
					flag = true;
				}
				else{
					if((arr[i][0] == arr[i + 1][0]) && (arr[i][1] < arr[i+1][1])){
						arr[i][0] = arr[i][0] ^ arr[i + 1][0];
						arr[i + 1][0] = arr[i][0] ^ arr[i + 1][0];
						arr[i][0] = arr[i][0] ^ arr[i + 1][0];
						arr[i][1] = arr[i][1] ^ arr[i + 1][1];
						arr[i + 1][1] = arr[i][1] ^ arr[i + 1][1];
						arr[i][1] = arr[i][1] ^ arr[i + 1][1];
						flag = true;						
					}
				}
			}
			if(flag == false)
				break;
		}	
		distance = 0;
		for(i = 0; i < tests - 1; ++i){
			distance += Distance(arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
		}
		
		cout << fixed << setprecision(2) << distance << endl;
		--cases;
	}
	return 0;
}
