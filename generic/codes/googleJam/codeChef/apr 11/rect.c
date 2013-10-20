#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main ()
{
  	map<int,int> datamap;
	map<string,int> mymap;
  	map<string,int>::iterator it;
	string s;
	int n, x, y, r, sv, lv, i, f;
	scanf("%d", &n);
	while(n>0){
		int c = 0;
		datamap.clear();
		mymap.clear();
		while(n > 0){
			scanf("%d %d", &x, &y);
			s = "";
			if(datamap[x]){
				if(datamap[x] > y){
					lv = y;
					sv = datamap[x];
				}
				else{
					sv = y;
					lv = datamap[x];
				}
				++c;
				while(lv){
					s += (lv % 10 + '0');
					lv /= 10;
				}
				while(sv){
					s += (sv % 10 + '0');
					sv /= 10;
				}
				++mymap[s];
				datamap.erase(x);
			}
			else
				datamap[x] = y;
			--n;
		}
		r = 0;
		//for(it = mymap.begin(); it != mymap.end(); ixt++ )
		//	cout << (*it).first << " => " << (*it).second << endl;
		for(it = mymap.begin(); it != mymap.end(); it++ ){
			f = 1;
			i = lv = (*it).second;
		    	if(lv > 1){
				for(; i > lv - 2; --i)
					f *= i;			
			}
			r += f / 2;
		}
		printf("%d\n",r);
		scanf("%d", &n);
		//cout << endl << n;
	}
	return 0;
}
