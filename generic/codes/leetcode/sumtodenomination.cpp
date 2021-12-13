/**************************************************************************************************
 * Coin Change 2
 * You are given an integer array coins representing coins of different denominations and an integer
 *  amount representing a total amount of money. Return the number of combinations that make up that
 *  amount. If that amount of money cannot be made up by any combination of the coins, return 0.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * The answer is guaranteed to fit into a signed 32-bit integer.
 * 
 * Example 1:
 *  Input: amount = 5, coins = [1,2,5]
 *  Output: 4
 *  Explanation: there are four ways to make up the amount:
 *      5=5
 *      5=2+2+1
 *      5=2+1+1+1
 *      5=1+1+1+1+1
 * 
 * Example 2:
 *  Input: amount = 3, coins = [2]
 *  Output: 0
 *  Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * Example 3:
 *  Input: amount = 10, coins = [10]
 *  Output: 1
 * 
 * Constraints:
 *  1 <= coins.length <= 300
 *  1 <= coins[i] <= 5000
 *  All the values of coins are unique.
 *  0 <= amount <= 5000
 * 
 * Solution From Amazon : https://www.educative.io/m/coin-changing-problem
 * Runtime Complexity: Quadratic - O(m ∗ n)
 * Memory Complexity: Linear, O(n)
 * 
 * To solve this problem, we’ll keep an array of size amount + 1. One additional space is reserved
 * because we also want to store the solution for the 0 amount.
 * 
 * There is only one way you can make a change of 0, i.e., select no coin so we’ll initialize
 *  solution[0] = 1. We’ll solve the problem for each amount, denomination to amount, using coins
 *  up to a denomination, den.
 * 
 * The results of different denominations should be stored in the array solution. The solution for
 * amount x using a denomination den will then be:
 * 
 * solution[x] = solution[x] + solution[x - den]
 * We’ll repeat this process for all the denominations, and at the last element of the solution
 * array, we will have the solution.
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> changeComb;
        changeComb.resize(amount + 1);
        changeComb[0] = 1;
        int i = 1;
        for(int coin : coins)
        {
            for(i = coin ; i< amount + 1; ++i)
            {
                changeComb[i] += changeComb[i - coin];
            }
        }
        return changeComb[amount];
    }
};

int main()
{
    Solution ob;
    
    {
        int coins[] = {1,2,5};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(coins[i]);
        cout << ob.change(5, nums) << endl;
    }
    return 0;
}
