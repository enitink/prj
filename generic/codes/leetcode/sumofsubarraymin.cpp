/*****************************SOLVED with TLE**********************************
Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
******************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

#define MODULO(X) X/(1000000007)


void displayVector(vector<vector<int> >& result)
{
    vector<vector<int> >::iterator itr = result.begin();
    vector<vector<int> >::iterator eitr = result.end();

    for( ; itr != eitr; ++itr)
    {
        vector<int>::iterator litr = itr->begin();
        vector<int>::iterator leitr = itr->end();

        cout << "[";
        for( ; litr != leitr; ++litr)
            cout << *litr << ", ";
        cout << "] ,";
    }
    return;
}

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int asize = arr.size();
        int * resultmat = new int[asize*asize];
        int i = 0, j;
        int sum = 0;
        if (asize)
        {
            for ( ; i<asize; ++i)
            {    
                resultmat[i + (i * asize)] = arr[i];
                sum += arr[i];
                sum = (sum % 1000000007);
            }
        }
        for(i=1; i<asize; ++i)
        {
            for(j=i-1; j>=0; --j)
            {
                resultmat[j + (i * asize)] =
                 (resultmat[(j+1) + (i * asize)] < 
                    resultmat[j + ((i-1) * asize )]) ? 
                        resultmat[(j+1) + (i * asize)] :
                            resultmat[j + ((i-1) * asize )];
                sum += resultmat[j + (i * asize)];
                sum = (sum % 1000000007);
            }
        }
        delete [] resultmat;
        return sum;
    }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {3,1,2,4};
        int i = 0;
        vector<int> arr;
        for (; i < 4; ++i)
            arr.push_back(maxarr[i]);
        cout << ob.sumSubarrayMins(arr) << endl;
    }

    {
        int maxarr[] = {11,81,94,43,3};
        int i = 0;
        vector<int> arr;
        for (; i < 5 ; ++i)
            arr.push_back(maxarr[i]);
        cout << ob.sumSubarrayMins(arr) << endl;
    }
    return 0;
}