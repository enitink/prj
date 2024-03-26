#include <iostream>
#include <vector>
using namespace std;
// Write any include statements here

int getMinimumDeflatedDiscCount(int N, vector<int> R) {
  int pos = N - 1;
  int result = 0;
  int prev = R[pos];
  pos = pos - 1;
  for( ; pos >=0; --pos)
  {
    cout << "prev " << prev << " pos " << pos << " R[pos] " << R[pos] << " Result " << result << endl;
     if (R[pos] >= prev)
     {
       R[pos] = prev - 1;
       ++result;
     }
    if (R[pos] == 0)
       return -1;
    prev = R[pos];
  }
  return result;
}


int main()
{
    //N = 5
    //R = [2, 5, 3, 6, 5]
    int arr[5] = {2, 5, 3, 6, 5};
    vector<int> D(arr, arr + 6);
    cout << getMinimumDeflatedDiscCount(5, D) << endl;

    // N = 3 : S = [100, 100, 100]
    int arr2[3] = {100, 100, 100};
    vector<int> D2(arr2, arr+4);
    cout << getMinimumDeflatedDiscCount(3, D2) << endl;

}