#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> posq;

        int n = nums.size(), i = 0;
        for ( ;i<n; ++i)
        {
            while (!posq.empty() && nums[i] > nums[posq.back()])
            {
                posq.pop_back();
            }
            posq.push_back(i);
            if (i-posq.front() >= k)
            {
                posq.pop_front();
            }
            if (i+1>=k)
            {
                result.push_back(nums[posq.front()]);
            }
        }
        return result;
    }
};

void printvector(vector<int>& nums)
{
    cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ",";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    {
        vector<int> nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        vector<int> result = s.maxSlidingWindow(nums, k);
        printvector(result);
    }
    {
        vector<int> nums = {1};
        int k = 1;
        vector<int> result = s.maxSlidingWindow(nums, k);
        printvector(result);
    }
    {
        vector<int> nums = {1,-1};
        int k = 1;
        vector<int> result = s.maxSlidingWindow(nums, k);
        printvector(result);
    }
    {
        vector<int> nums = {9,11};
        int k = 2;
        vector<int> result = s.maxSlidingWindow(nums, k);
        printvector(result);
    }
    {
        vector<int> nums = {4,-2};
        int k = 2;
        vector<int> result = s.maxSlidingWindow(nums, k);
        printvector(result);
    }
    {
        vector<int> nums = {1,3,1,2,0,5};
        int k = 3;
        vector<int> result = s.maxSlidingWindow(nums, k);
        printvector(result);
    }
    cout << endl;
    return 0;
}