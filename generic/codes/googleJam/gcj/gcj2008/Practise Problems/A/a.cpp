#include	<iostream>
#include	<string>

using namespace std;

#define		floop(i,s,e)	for(i = s; i < e; ++i)

string alienno, srclang, targlang, result;

void convert(){
	int dec, loc, i, j, pow;
	int alienno_len = alienno.length();
	int srclang_len = srclang.length();
	int targlang_len = targlang.length();
	dec = 0;
	pow = 1;
	for(i = alienno_len - 1; i >= 0; --i){
		dec += srclang.find(alienno[i], 0) * pow;
		pow *= srclang_len;
	}
	result.clear();
	do{
		j = dec % targlang_len;
		result.push_back(targlang.at(j));
		dec /= targlang_len;
	}while(dec);
}

int main(){
	int n, i, j;
	cin >> n;

	floop(i,1,n + 1){
		cin >> alienno >> srclang >> targlang;
		convert();		
		cout << "Case #" << i << ": ";
		for(j = result.size() - 1; j >= 0; --j)
			cout << result.at(j);
		cout << endl;
	}
	return 0;
}
