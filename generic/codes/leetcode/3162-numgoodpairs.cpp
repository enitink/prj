#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;


class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int result = 0;
        int n = nums1.size(), i;
        int m = nums2.size(), j;
        for (i=0;i<n;++i){
            for (j=0;j<m;++j){
                if (nums1[i] % (nums2[j] * k) == 0) {
                    result++;
                }
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {1,2,3,4,5};
    int k = 10;
    cout << s.numberOfPairs(nums1, nums2, k) << endl;
    return 0;
}