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