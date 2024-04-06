/**************************************SOLVED*******************************************************
 70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
**************************************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        memset(combinations, 0, sizeof(int) * 46);
        int i = 2;
        combinations[0] = 1;
        combinations[1] = 1;

        for(; i<=n; ++i)
        {
            combinations[i] = combinations[i-1] + combinations[i - 2];
        }

        return combinations[i];
    }
private:

    int combinations[46];
};

int main()
{
    Solution ob;

    cout << endl << ob.climbStairs(2);
    cout << endl << ob.climbStairs(3);
    cout << endl << ob.climbStairs(7);
    cout << endl << ob.climbStairs(10);


    return 0;
}