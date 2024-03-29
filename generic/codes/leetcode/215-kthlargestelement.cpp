#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int ln = nums.size() , i = 0;

        for ( ; i<ln; ++i)
            pq.push(nums[i]);
        --k;
        while(k-- && !pq.empty())
            pq.pop();
        return pq.top();
    }
};

int main()
{
    Solution ob;

    {
        int arr[] = {3,2,1,5,6,4};
        vector<int> nums(arr, arr+6);
        int i = 0;
        cout << ob.findKthLargest(nums, 2) << endl;
    }
    {
        int arr[] = {3,2,3,1,2,4,5,5,6};
        vector<int> nums(arr, arr+9);
        int i = 0;
        cout << ob.findKthLargest(nums, 4) << endl;
    }

    return 0;
}