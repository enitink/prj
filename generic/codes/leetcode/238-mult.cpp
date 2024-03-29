#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nlen = nums.size(), i = 0;
        vector<int> result(nlen);
        vector<int> prefix(nlen);
        vector<int> postfix(nlen);
        int prev=1, rprev = 1;
        for( ; i<nlen; ++i)
        {
            prefix[i] = prev;
            prev *= nums[i];
            postfix[nlen - (i+1)] = rprev;
            rprev *= nums[nlen - (i+1)];
        }
        for( i=0; i<nlen; ++i)
        {
            result[i] = prefix[i] * postfix[i];
        }
        return result;
    }
};

int main()
{
    Solution ob;
    {
        int arr[] = {1, 2, 3, 4};
        vector<int> nums(arr, arr+4);
        vector<int> result = ob.productExceptSelf(nums);
        int rlen = result.size(), i = 0;
        for( ; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    {
        int arr[] = {-1,1,0,-3,3};
        vector<int> nums(arr, arr+5);
        vector<int> result = ob.productExceptSelf(nums);
        int rlen = result.size(), i = 0;
        for( ; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}