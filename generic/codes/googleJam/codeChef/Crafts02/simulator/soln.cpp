#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cstring>

#include	<cmath>
#ifndef PI
#define PI 3.14159265358979323846  
#endif
 
#define DEG_CIRCLE 360
//#define DEG_TO_RAD (M_PI / (DEG_CIRCLE / 2))
#define RAD_TO_DEG ((DEG_CIRCLE / 2) / M_PI)
 
/*inline double deg2rad(double degrees)
{
    return degrees * DEG_TO_RAD;
}*/
 
inline double rad2deg(double radians)
{
    return radians * RAD_TO_DEG;
} 


int main(){
	int i, time;
	float D, n, cald;
	float arr[25][25];
	while(true){
		cin >> D >> n;
		time = -1;
		memset(arr, 0, sizeof(arr));
		if((D == -1) && (n == -1))
			break;
		for(i = 0; i < n; ++i){
			cin >> a[i][0] >> a[i][1];
		}
		cald = sqrt((a[0][0] * a[0][0]) - (a[n][0] * a[n][0]) + (a[0][1] * a[0][1]) - (a[n][1] * a[n][1]));
		if(cald >= D){
			time = D;
		}
		if(time > 0)
			cout << "impossible" << endl;
	}
}
