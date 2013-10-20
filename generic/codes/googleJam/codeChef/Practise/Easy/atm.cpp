//Problem Statement: Prgram jst to find.. if a transaction is possible or not.. for given balance, withdrawing amt & bank charges
#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<iomanip>
using std::setprecision;
using std::showpoint;
using std::fixed;

int main(){
	float bal = 0.0;
	int amt;
	cin >> amt >> bal;
	if(((bal - amt) >= 0.5) && ((amt % 5) == 0))
			bal =  bal - 0.5 - amt;
	cout << showpoint << fixed << setprecision(2) << bal << endl;
	return 0;
}
