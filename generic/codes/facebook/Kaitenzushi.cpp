#include <iostream>
#include <queue>
#include <map>

using namespace std;
// Write any include statements here

typedef struct _mapAndQueue
{
  _mapAndQueue(int s) : size(s){}
  void insert(int val)
  {
    if (mq.size() == size)
    {
        int oval = mq.front();
        mq.pop();
        map<int, bool>::const_iterator it = mp.find(oval);
        mp.erase(it);
    }
    mq.push(val);
    mp[val] = true;
  }
  bool found(int val)
  {
    return (mp.find(val) != mp.end()) ? true : false;
  }

  int size;
  queue<int> mq;
  map<int, bool> mp;
}mapAndQueue;

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
  int result = 0, i = 0;
  mapAndQueue mpq(K);
  for ( ;i<N; ++i)
  {
    if (mpq.found(D[i]))
    {
        continue;
    }
    mpq.insert(D[i]);
    ++result;
  }
  return result;
}

int main()
{
    int arr[6] = {1, 2, 3, 3, 2, 1};
    vector<int> D(arr, arr + 7);
    cout << endl << getMaximumEatenDishCount(6, D, 1);
    cout << endl << getMaximumEatenDishCount(6, D, 2);
    return 0;
}
