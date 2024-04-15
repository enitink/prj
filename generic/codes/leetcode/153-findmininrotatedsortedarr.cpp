#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int binarySearchMin(vector<int>& nums, int l, int r) {
        if ((nums[l] < nums[r]) && (l-1 >=0) && (nums[l] < nums[l-1])) {
            return nums[l];
        }
        if (l == r) {
            return nums[l];
        }
        int mid = l + (r-l)/2;
        if (nums[mid] > nums[r]) {
            return binarySearchMin(nums, mid+1, r);
        } else {
            return binarySearchMin(nums, l, mid);
        }
    }

public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums[nums.size()-1]) {
            return nums[0];
        }
        return binarySearchMin(nums, 0, nums.size()-1);
    }
};


int main() {
    Solution sol;
    
    {
        vector<int> nums = {3,4,5,1,2};
        cout << sol.findMin(nums) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << sol.findMin(nums) << endl;
    }
    {
        vector<int> nums = {17,13,15,17};
        cout << sol.findMin(nums) << endl;
    }
    {
        vector<int> nums = {1,2,3,4,5};
        cout << sol.findMin(nums) << endl;
    }
    return 0;
}