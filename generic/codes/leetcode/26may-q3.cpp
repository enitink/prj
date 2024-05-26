#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        long long result = 0;
        int n = nums1.size(), i;
        int m = nums2.size(), j;

        for(i=0;i<n;++i) {
            if (nums1[i]%k == 0)
                nums1[i] /= k;
            else
                nums1[i] = 0;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for(i=0;i<n;++i)
            if (nums1[i] != 0)
                break;

        for (;i<n;++i){
            vector<int>::iterator up = upper_bound(nums2.begin(), nums2.end(), nums1[i]);
            int pos = (up - nums2.begin());
            for (j=pos;j>=0;--j){
                if (nums1[i] % (nums2[j]) == 0) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
     {
        vector<int> nums1 = {1,2,4,12};
        vector<int> nums2 = {3,1,1,8};
        int k = 2;
        cout << s.numberOfPairs(nums1, nums2, k) << endl;
     }
    return 0;
}


/*1 <= n, m <= 10^5
1 <= nums1[i], nums2[j] <= 10^6
1 <= k <= 103

1 <= n, m <= 50
1 <= nums1[i], nums2[j] <= 50
1 <= k <= 50*/