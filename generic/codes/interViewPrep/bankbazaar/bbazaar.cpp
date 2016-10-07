#include <iostream>
using namespace std;

#define MAXSIZE 500

#define FUNC(X,Y,Z) { \
                    if ( ((X) < r) && ((Y) < c) && ((X) >= 0)  && ((Y) >= 0) ) \
                    { \
                        if (arr[X][Y] == 2) \
                            Z = 1; \
                        else if (arr[X][Y] == 0) \
                            Z =-1; \
                        else \
                        { \
                            position_s newp; \
                            newp.r = X; \
                            newp.c = Y; \
							dipped = true; \
                            Z = minroute(arr,r,c,newp); \
                        } \
                    } \
                    }

typedef struct
{
    int r;
    int c;
}position_s;


int minroute(int arr[][MAXSIZE], int r, int c, position_s& start)
{
    int lr, rr, dc, uc, min = 1000000;
    lr = rr = dc = uc = -1;
	bool dipped = false;
   // cout << "Start :" << start.r << " " << start.c << endl;
    arr[start.r][start.c] = 0;

    FUNC(start.r+1, start.c, dc)
    min = (dc == -1) ? min : dc;
    FUNC(start.r-1, start.c, uc)
    min = (uc == -1) ? min : ( min < uc ) ? min : uc;
    FUNC(start.r, start.c+1, rr)
    min = (rr == -1) ? min : ( min < rr ) ? min : rr;
    FUNC(start.r, start.c-1, lr)
    min = (lr == -1) ? min : ( min < lr ) ? min : lr;
    return (min == 1000000) ? - 1 : (dipped) ? min+1 : min;
}

int main() {
	// your code goes here
	int t,n,m,i,j;
	int arr[MAXSIZE][MAXSIZE];
	char c;
    position_s start;
    position_s end;
    
	cin >> t;
	while(t--)
	{
	    cin >> n >> m;
	    for(i=0;i<n;++i)
	    {
	        for(j=0;j<m;++j)
	        {
	            cin >> c;
	            if (c == 'B')
	            {
	                start.r = i;
	                start.c = j;
	                arr[i][j] = -1;
	            }
	            else if (c == 'C')
	            {
	                end.r = i;
	                end.c = j;
	                arr[i][j] = 2;
	            }
	            else if (c == 'D')
	                arr[i][j] = 0;
	            else
	                arr[i][j] = 1;
	        }
	    }
	    cout << minroute(arr, n, m, start) << endl;
	}
	return 0;
}
