#include <iostream>
#include <vector>

using namespace std;

// search the other value in the list using lowerbound
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0;
        int lenn = numbers.size();
        vector<int> result;
        for( ; st<lenn-1; ++st)
        {
            int searchval = target - numbers[st];
            vector<int>::iterator it = lower_bound(numbers.begin() + st + 1, numbers.end(), searchval);
            if ( (it != numbers.end()) && (*it == searchval) )
            {
                result.push_back(st + 1);
                result.push_back(it - numbers.begin() + 1);
                break;
            }
        }
        return result;
    }
};

// Using two pointers, start with start and end positions. If sum of start and end is more. then decrease end by 1,  else increase start by 1.
// keep doing till values are find.
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lenn = numbers.size();
        int start = 0, end = lenn - 1;

        vector<int> result;
        while(true)
        {
            if (numbers[start] + numbers[end] == target)
            {
                result.push_back(start + 1);
                result.push_back(end + 1);
                break;
            }
            else if (numbers[start] + numbers[end] < target)
                start++;
            else
                end--;
        }
        return result;
    }
};
int main()
{
    Solution ob;

    {
        int tar[] = {-1, 0};
        vector<int> heights(tar, tar+2);
        vector<int> result = ob.twoSum(heights, -1);
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}