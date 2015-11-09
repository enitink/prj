#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  int myints[] = {0,2,3,4,5};
  int * low;

  low=upper_bound (myints, myints+5, 1);

  cout << "lower_bound at position " << *low << endl;
  cout << "position" << (int)(low - myints);
  return 0;
}
