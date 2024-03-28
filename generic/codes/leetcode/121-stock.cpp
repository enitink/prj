/***************************************SOLVED***************************************************
121. Best Time to Buy and Sell Stock
 
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a
different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

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