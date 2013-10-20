#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cmath>
#include	<cstring>
#include	<iomanip>

using std::setprecision;
using std::fixed;

#include	<algorithm>

using std::sort;

#define		Distance(X1,Y1,X2,Y2)		sqrt(((X1 - X2) * (X1 - X2)) + ((Y1 - Y2) * (Y1 - Y2)))
#define		SIZE				100001

class points{
public:
	int x;
	int y;
	
};

points arr[SIZE];

int main(){
	int cases, i, tests, j;
//	float distance;
	cin >> cases;
	while(cases){
		cin >> tests;
		memset(arr, 0, sizeof(arr));
		for(i = 0; i < tests; ++i)
			cin >> arr[i].x >> arr[i].y;
//		sort(arr[0], arr[tests - 1]);
		for(i = 0; i < tests; ++i)
			cout << endl << arr[i].x << " " << arr[i].y;
//		distance = 0;
//		for(i = 0; i < tests - 1; ++i){
//			distance += Distance(arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
//		}
		
//		cout << fixed << setprecision(2) << distance << endl;
		--cases;
	}
	return 0;
}
