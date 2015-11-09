#include <iostream>
#include <map>

using namespace std;

int main(){
	int t, n , k, a, flag, count, tn, v, odd, ch, total = 0;;
	cin >> t;

	map<int, int> datamap;
	map<int,int>::iterator it;

	while(t){
		cin >> n >> k;
		flag = 0;
		datamap.clear();
		tn = n;
		v = n / k;
		while(n){
			cin >> a;
			++datamap[a];
			if(datamap[a] > v){
				flag = 1;
				break;
			}
			++total;
			--n;
		}
		if(1 == flag)
			cout << "-1";
		else{
			n = v;
			while(tn){
				count = 0;				
				odd = 0;
				it = datamap.begin();
				//it += 1;
				for ( ; it != datamap.end(); ++it ){
					if(v == (*it).second)
						++odd;
					++total;
				}
				ch = 0;
				//cout << endl;
				for ( it=datamap.begin() ; it != datamap.end() && count < k; it++){
					if(!(*it).second)
						continue;
					if(((*it).second != v) && (ch + odd < n)){
						++ch;
			    			cout << (*it).first << " ";
					}
					else{
						if((*it).second != v)
							continue;
						--odd;
						cout << (*it).first << " ";
					}
					--(*it).second;
					++count;
					--tn;
					if(!(*it).second)
						datamap.erase(it);
					++total;
				}
				--v;
			}
		}
		cout << endl;
		--t;
	}
	cerr << total;
	return 0;
}
