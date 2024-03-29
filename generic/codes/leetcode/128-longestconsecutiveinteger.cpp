#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0, lresult = 0, i = 0, lnums = nums.size();
        set<int> myset(nums.begin(), nums.end());

        for( ; i<lnums; ++i)
        {
            set<int>::iterator itr = myset.find(nums[i] - 1);
            if ( itr == myset.end())
            {
                lresult = 0;
                while ( myset.find(nums[i] + lresult) != myset.end())
                    ++lresult;
                result = (result > lresult) ? result : lresult;
                if (result > lnums/2)
                    break;
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;
    {
        int arr[] = {100,4,200,1,3,2};
        vector<int> nums(arr, arr+6);
        cout << ob.longestConsecutive(nums) << endl;
    }
    {
        int arr[] = {0,3,7,2,5,8,4,6,0,1};
        vector<int> nums(arr, arr+10);
        cout << ob.longestConsecutive(nums) << endl;
    }
    {
        int arr[] = {1,2,0,1};
        vector<int> nums(arr, arr+4);
        cout << ob.longestConsecutive(nums) << endl;
    }
    {
        vector<int> nums; nums.push_back(0);
        cout << ob.longestConsecutive(nums) << endl;
    }
    {
        vector<int> nums;
        nums.push_back(0);nums.push_back(0);
        cout << ob.longestConsecutive(nums) << endl;
    }
    {
        vector<int> nums;
        cout << ob.longestConsecutive(nums) << endl;
    }
    return 0;
}