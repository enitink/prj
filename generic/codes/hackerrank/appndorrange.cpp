#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int s,t,a,b,m,n,i,res,d;
    cin >> s >> t >> a >> b >> m >> n;
    res = 0;
    for (i=0;i<m;++i){
        cin >> d;
        //if ( ((unsigned int)((a+d) - s)) < (t-s) )
        if ( (a+d) >= s && (a+d) <= t)
            ++res;
    }
    cout << res << endl;
    res = 0;
    for (i=0;i<n;++i){
        cin >> d;
        //if ( ((unsigned int)((b+d) - s)) < (t-s) )
        if ( (b+d) >= s && (b+d) <= t)
            ++res;
    }
    cout << res;
    return 0;
}

