#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

int main ()
{
  	map<long int, long int> datamap;
	map<string,long long int> mymap;
  	map<string,long long int>::iterator it;
	long int x, y;
	int n;
	char s[2 * sizeof(long int)];
	long long int r;
	struct{
		long int s;
		long int l;
	}st;
	scanf("%d", &n);
	while(n>0){
		datamap.clear();
		mymap.clear();
		while(n > 0){
			scanf("%ld %ld", &x, &y);
			if(datamap.find(x) != datamap.end()){
				if(datamap[x] > y){
					st.l = y;
					st.s = datamap[x];
				}
				else{
					st.s = y;
					st.l = datamap[x];
				}
				memcpy(&s,&st,8);
				++mymap[s];
				datamap.erase(x);
			}
			else
				datamap[x] = y;
			--n;
		}
		//for(it = mymap.begin(); it != mymap.end(); it++ )
		//	cout << (*it).first << " => " << (*it).second << endl;
		r = 0;
		for(it = mymap.begin(); it != mymap.end(); it++ ){
				r += ((*it).second * ((*it).second -  1)) / 2;
				
		}
		printf("%lld\n",r);
		scanf("%d", &n);
	}
	return 0;
}
