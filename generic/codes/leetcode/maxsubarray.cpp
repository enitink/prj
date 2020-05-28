#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto itr = nums.begin();
        auto eitr = nums.end();
        int result = *itr;
        int lsum = *itr;
        ++itr;
        for( ; itr!=eitr; ++itr)
        {
            lsum += *itr;
            lsum = (lsum < *itr) ?  *itr : lsum;
            if (lsum > result)
                result = lsum;
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        cout << ob.maxSubArray(nums);
    }
    {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        cout << endl << ob.maxSubArray(nums);
    }
    {
        vector<int> nums = {-1,-2,-3,-4,-5,-6,-7,-8,-9};
        cout << endl << ob.maxSubArray(nums);
    }
    {
        vector<int> nums = {-1,-2,-3,-4,5,-6,-7,-8,-9};
        cout << endl << ob.maxSubArray(nums);
    }
    return 0;
}