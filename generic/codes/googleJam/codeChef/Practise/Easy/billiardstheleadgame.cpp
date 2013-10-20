#include	<iostream>
using std::cin;
using std::cout;
using std::endl;

#include	<algorithm>
using std::max_element;
using std::min_element;

int main(){
	int rounds, s, t, max = 0, min = 0;
	cin >> rounds;
	int * leadtable = new int(rounds);
	for(int i = 0; i < rounds; ++i){
		cin >> s >> t;
		max += s;
		min += t;
		leadtable[i] = max - min;
	}
	max = *max_element(leadtable, leadtable + rounds);
	min = *min_element(leadtable, leadtable + rounds);
	if(max > abs(min))
		cout << 1 << " " << max << endl;
	else
		cout << 2 << " " << abs(min) << endl; 
	return 0;
}
