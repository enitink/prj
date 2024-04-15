#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }

        return (goal == 0);
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {2,3,1,1,4};
        cout << s.canJump(nums) << endl;
    }
    {
        vector<int> nums = {3,2,1,0,4};
        cout << s.canJump(nums) << endl;
    }
    {
        vector<int> nums = {0};
        cout << s.canJump(nums) << endl;
    }
    return 0;
}