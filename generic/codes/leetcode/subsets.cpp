/***************************************SOLVED****************************************************
78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        int scount = 1 << nums.size();

        for(int i = 0; i < scount; ++i)
        {
            vector<int> lresult;
            int tempi = i;
            int pos = 0;
            while(tempi)
            {
                if (tempi&1)
                {
                    lresult.push_back(nums[pos]);
                }
                tempi >>= 1;
                ++pos;
            }
            result.push_back(lresult);
        }
        return result;
    }
};

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

int main()
{
    Solution ob;

    {
        int maxarr[] = {1,2,3};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        vector<vector<int> > result = ob.subsets(nums);

        displayVector(result);
    }
    return 0;
}