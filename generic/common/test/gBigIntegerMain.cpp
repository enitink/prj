#include <gBigInteger.h>

using namespace gen::common::bigInt;
using namespace std;

int main()
{
	gBigInteger ob;
	gBigInteger ob1;

	cin >> ob >> ob1;

	cout << ob + ob1 << endl;
	cout << ob << " " << ob1;
	ob += ob1;
	cout << ob << " " << ob1;
	return 0;
}
