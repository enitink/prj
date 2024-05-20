/*
We aim to maximize the sum of values of all nodes in an undirected tree by performing a specific operation. The operation allows us to replace the values of any two adjacent nodes with their XOR values, with a given integer k.

Key Observations:

Alice can perform an operation on any edge [u, v] by XOR-ing the values of nodes u and v with a positive integer k.
Alice wants to maximize the sum of the values of the tree nodes. This means she aims to maximize the total value represented by the sum of individual node values after performing the specified operations.
Alice can perform the operation any number of times (including zero) on the tree. This implies she can selectively choose edges and perform the XOR operation to maximize the sum of node values.

Algorithm

Main Function: maximumValueSum(nums, k, edges)

1. Initialize a 2D memoization array memo with all values set to -1.
2. Call the helper function maxSumOfNodes with the initial parameters:
    index = 0
    isEven = 1 (start with an odd number of elements)
    nums = the input array
    k = the given XOR value
    memo = the initialized memoization array
3. Return the result from the maxSumOfNodes function.

Recursive Function: maxSumOfNodes(index, isEven, nums, k, memo)

1. If the index is equal to the size of the nums array, return:
    If isEven is 1, return 0 (no operation performed on an odd number of elements).
    Else, return INT_MIN.
2. If the result for the current index and isEven is already memoized, return the memoized value.
3. Calculate the maximum sum of nodes in two cases:
    noXorDone: No XOR operation is performed on the current element.
        The sum is the current element value nums[index] plus the maximum sum of the remaining elements.
    xorDone: The XOR operation is performed on the current element.
        The sum is the current element value nums[index] ^ k plus the maximum sum of the remaining elements with isEven flipped.
4. Memoize the maximum of noXorDone and xorDone, and return the result.

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        return maxSumOfNodes(0, 1, nums, k, memo);
    }

private:
    long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k,
                            vector<vector<long long>>& memo) {
        if (index == nums.size()) {
            // If the operation is performed on an odd number of elements return
            // INT_MIN
            return isEven == 1 ? 0 : INT_MIN;
        }
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }
        // No operation performed on the element
        long long noXorDone =
            nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
        // XOR operation is performed on the element
        long long xorDone = (nums[index] ^ k) +
                            maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        // Memoize and return the result
        return memo[index][isEven] = max(xorDone, noXorDone);
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int k = 3;
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};
        cout << sol.maximumValueSum(nums, k, edges) << endl;
    }
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int k = 3;
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
        cout << sol.maximumValueSum(nums, k, edges) << endl;
    }
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int k = 3;
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5},
                                     {3, 6}};
        cout << sol.maximumValueSum(nums, k, edges) << endl;
    }

    return 0;
}