/*******************************************************************************
 * 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number

You are given a string num, representing a large integer, and an integer k.

We call some integer wonderful if it is a permutation of the digits in num and is greater in value than num. There can be many wonderful integers. However, we only care about the smallest-valued ones.

For example, when num = "5489355142":
The 1st smallest wonderful integer is "5489355214".
The 2nd smallest wonderful integer is "5489355241".
The 3rd smallest wonderful integer is "5489355412".
The 4th smallest wonderful integer is "5489355421".
Return the minimum number of adjacent digit swaps that needs to be applied to num to reach the kth smallest wonderful integer.

The tests are generated in such a way that kth smallest wonderful integer exists.

 

Example 1:

Input: num = "5489355142", k = 4
Output: 2
Explanation: The 4th smallest wonderful number is "5489355421". To get this number:
- Swap index 7 with index 8: "5489355142" -> "5489355412"
- Swap index 8 with index 9: "5489355412" -> "5489355421"
Example 2:

Input: num = "11112", k = 4
Output: 4
Explanation: The 4th smallest wonderful number is "21111". To get this number:
- Swap index 3 with index 4: "11112" -> "11121"
- Swap index 2 with index 3: "11121" -> "11211"
- Swap index 1 with index 2: "11211" -> "12111"
- Swap index 0 with index 1: "12111" -> "21111"
Example 3:

Input: num = "00123", k = 1
Output: 1
Explanation: The 1st smallest wonderful number is "00132". To get this number:
- Swap index 3 with index 4: "00123" -> "00132"
 

Constraints:

2 <= num.length <= 1000
1 <= k <= 1000
num only consists of digits.
*******************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void nextPermutation(string& nums) {
        int numsize = nums.size();
        int i = numsize - 1;
        int index = -1;
        for ( ; i>0; --i)
        {
            if (nums[i] > nums[i-1])
            {
                index = i - 1;
                break;
            }
        }
        if (-1 != index )
        {
            i = numsize - 1;
            for ( ; i>0; --i)
            {
                if (nums[i] > nums[index])
                {
                    int temp = nums[i];
                    nums[i] = nums[index];
                    nums[index] = temp;
                    break;
                }
            }
        }
        sort(nums.begin() + (index+1), nums.end());
    }
public:
    int getMinSwaps(string num, int k) {
        string nextnum = num;
        int i=1;
        for(; i<=k; ++i)
        {
            nextPermutation(nextnum);
        }
        int result = 0;
        for(i=0; i<num.size(); ++i)
        {
            if(num[i] == nextnum[i])
                continue;
            int start = i + 1;
            while (nextnum[i] != num[start])
            {
                start++;
            }
            while (i != start)
            {
                swap(num[start], num[start - 1]);
                start--;
                result++;
            }
        }
        return result;
    }
};


int main()
{
    Solution ob;

    cout << ob.getMinSwaps("5489355142", 4) << endl;
    cout << ob.getMinSwaps("11112", 4) << endl;
    cout << ob.getMinSwaps("00123", 1) << endl;

    return 0;
}

