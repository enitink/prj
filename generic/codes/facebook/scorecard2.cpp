#include <iostream>
#include <vector>

using namespace std;

void getMinCount(int max, int* arr, bool isOddPresent)
{
    while (max != 0)
    {
        while(max >= 2)
        {
            int r = max % 2;
            arr[1] = (max - r ) / 2;
            max = r;
        }
        if (max >= 1)
        {
            arr[0] = 1;
        }
    }
    if ((isOddPresent) && arr[0] == 0)
    {
        arr[0] = 2;
        arr[1] = arr[1] - 1;
    }
}

int getMinProblemCount(int N, vector<int> S) {
  int i = 0;
  int max = 0;
  bool isOddPresent = false;
  for ( ; i< N; ++i)
  {
    if (S[i] % 2)
        isOddPresent = true;
    max = max > S[i] ? max : S[i];
  }
  int arr[2] = {};
  getMinCount(max, arr, isOddPresent);

  return arr[1] + arr[0];
}

int main()
{
    //N = 6  : S = [1, 2, 3, 4, 5, 6]
    int arr[6] = {1, 2, 3, 4, 5, 6};
    vector<int> D(arr, arr + 7);
    cout << getMinProblemCount(6, D) << endl;

    // N = 4 : S = [4, 3, 3, 4]
    int arr2[4] = {4, 3, 3, 4};
    vector<int> D2(arr2, arr+5);
    cout << getMinProblemCount(4, D2) << endl;

}