/*********************************SOLVED********************************************************
60. Permutation Sequence

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!

Solution : Understanding it from https://www.educative.io/blog/crack-amazon-coding-interview-questions#questions
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int factorial(int n)
    {
        if ((n == 0) || (n == 1))
            return 1;
        return (n * factorial(n-1));
    }
    void helper(vector<char>& nums, int k, string& result){
        if (nums.empty())
            return;
        int size = nums.size();
        int blocksize = factorial(size - 1);
        
        int pos = (k-1)/blocksize;
        
        result += nums[pos];
        
        nums.erase(nums.begin()+pos);
        
        helper(nums, k - (pos*blocksize), result); 
    }
    string getPermutation(int n, int k) {
        vector<char> nums;
    
        for(int i = 1; i <=n; ++i)
           nums.push_back(i + '0');
        
        string result;
        helper(nums, k, result);
        return result;
    }
};

int main()
{
    Solution ob;

    {
        cout << ob.getPermutation(3, 3);
    }
    return 0;
}