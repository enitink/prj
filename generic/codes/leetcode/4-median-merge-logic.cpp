#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void mergeArrays(vector<int>& nums1, vector<int>& nums2, vector<int>& merged, int n1size, int n2size)
    {
        int i = 0, j = 0, k = 0;
        
        while(i<n1size && j <n2size)
        {
            merged[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
        }
        while(i<n1size)
            merged[k++] = nums1[i++];
        while(j<n2size)
            merged[k++] = nums2[j++];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1size = nums1.size();
        int n2size = nums2.size();
        int mergedsize = n1size + n2size;
        
        vector<int> merged;
        merged.resize(n1size+n2size);

        mergeArrays(nums1,nums2,merged, n1size, n2size);

        if (mergedsize%2)
            return merged[mergedsize/2] * 1.0;
        else
        {
            return ( (merged[mergedsize/2]+ merged[(mergedsize/2)-1]) / 2.0);
        }
        
    }
};

int main()
{
    vector<int> nums1{1,2};
    vector<int> nums2{3,4};

    Solution ob;
    cout << ob.findMedianSortedArrays(nums1, nums2);

    return 0;
}