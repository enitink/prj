/***************************************SOLVED***************************************************
Solution Link: https://leetcode.com/submissions/detail/341325245/
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto itr = prices.begin();
        auto eitr = prices.end();
        int result = 0;
        if (prices.empty())
            return result;
        int lmin = *itr; ++itr;        
        for ( ; itr!= eitr; ++itr)
        {
            if (*itr < lmin) 
                lmin = *itr;
            else
            {
                result = ( result < (*itr - lmin)) ? (*itr - lmin) : result;
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        vector<int> nums = {7,1,5,3,6,4};
        cout << ob.maxProfit(nums);
    }
    {
        vector<int> nums = {7,6,4,3,1};
        cout << endl << ob.maxProfit(nums);
    }
    {
        vector<int> nums = {1,2,3,4,5,6,10};
        cout << endl << ob.maxProfit(nums);
    }
    {
        vector<int> nums = {};
        cout << endl << ob.maxProfit(nums);
    }
    return 0;
}