#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curEnd = 0;
        int curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i >= curEnd)
            {
                ++jumps;
                curEnd = curFarthest;
            }
        }

        return jumps;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {2,3,1,1,4};
        cout << s.jump(nums) << endl;
    }
    {
        vector<int> nums = {2,3,0,1,4};
        cout << s.jump(nums) << endl;
    }
    {
        vector<int> nums = {2,3,0,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        cout << s.jump(nums) << endl;
    }
    return 0;
}