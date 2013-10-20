//Program for printing reverse polish notation for any given expression

#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<stack>

using std::stack;

int main(){
	int noofdata;
	char ch;
	stack <char> ops;
	cin >> noofdata;
	cin.get();
	while(noofdata){
		while((ch = cin.get()) != '\n'){
			if((ch >= 'a') && (ch <= 'z'))
				cout << ch;
			else{
				if(ch == ')'){
					while(((ch = (char) ops.top()) != '(') && (!ops.empty())){
						cout << ch;
						ops.pop();
					}
					ops.pop();
				}
				else
					ops.push(ch);
			}
		}
		cout << endl;		
		--noofdata;
	}
	return 0;
}
