#include <iostream>
#include <vector>

using namespace std;

void getMinCount(int max, int* arr)
{
    while (max == 0)
    {
        while (max >= 3)
        {
            int r = max % 3;
            arr[2] = (max - r ) / 3;
            max = r; 
        }
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
}

int getMinProblemCount(int N, vector<int> S) {
  int i = 0;
  int max = 0;
  for ( ; i< N; ++i)
  {
    max = max > S[i] ? max : S[i];
  }
  int arr[3] = {};
  getMinCount(max, arr);

  for (i=0; i<N; ++i)
  {
    int larr[3];
  }

  return 0;
}

int main()
{

}