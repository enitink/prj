#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

#include	<cstring>

#include	<iomanip>
using std::setw;
using std::setfill;

#define		Chars		19
#define		base		1000000000

int main(){
	int cases, i, j;
	char ch;
	char string[] = "welcome to code jam";
	long int *cal1 = new long int[Chars];
	long int *cal2 = new long int[Chars];
	cin >> cases;
	cin.get();
	for(i = 0; i < cases; ++i){
		memset(cal1, 0, sizeof(int) * Chars);
		memset(cal2, 0, sizeof(int) * Chars);
		while((ch = cin.get()) != '\n'){
			for(j = 0; j < Chars; ++j){
				if(ch == string[j]){
					if(j == 0)
						cal2[j] =  (cal1[j] + 1) % base;
					else
						cal2[j] = (cal1[j] + cal1[j - 1]) % base;
				} else {
					cal2[j] = cal1[j];
					if(cal2[j] == 0)
						break;
				}
			}
			memcpy(cal1, cal2, sizeof(int) * Chars);
			memset(cal2, 0, sizeof(int) * Chars);			
		}
		cout << "Case #" << (i + 1) << ": " << setw(4) << setfill('0') << cal1[Chars - 1] % 10000 << endl;
	}
	return 0;	
}
