#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int arr[3][50001] = {};
        int vlen = nums.size();
        int res = 0;
        int maxdegree = 0;
        for (int i = 0; i < vlen; ++i)
        {
            int num = nums[i];
            ++arr[0][num];
            if(arr[0][num] == 1)
                arr[1][num] = i;
            else
                arr[2][num] = i;
            if (arr[0][num] > maxdegree)
                res = num;
            else if (arr[0][num] == maxdegree)
                res = ( (arr[2][res] - arr[1][res]) < (arr[2][num] - arr[1][num]) ) ? res : num;
        }
        
        return (arr[2][res] - arr[1][res] + 1);
    }
};

int main()
{
    Solution ob;

    {
         vector<int> nums = {1, 2, 2, 3, 1};
         cout << ob.findShortestSubArray(nums);
    }
    {
        vector<int> nums = {1,2,2,3,1,4,2};
        cout << endl << ob.findShortestSubArray(nums);
    }
    {
         vector<int> nums = {1, 2, 3, 4, 5};
         cout << endl <<  ob.findShortestSubArray(nums);
    }
    {
        vector<int> nums = {1};
        cout << endl << ob.findShortestSubArray(nums);
    }
    {
        vector<int> nums = {1,1,1,1,1,1};
        cout << endl << ob.findShortestSubArray(nums);
    }
    return 0;
}
