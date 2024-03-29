#include <iostream>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
         this->k = k;
         int ln = nums.size(), i = 0;
         for ( ;i<ln; ++i)
            add(nums[i]);
    }
    int add(int val) {
        vector<int>::iterator low = lower_bound(sortednums.begin(), sortednums.end(), val);
        if (low == sortednums.end())
            sortednums.push_back(val);
        else
            sortednums.insert(low, val);

        int res = (int)sortednums.size() - k;
        if (res >= 0)
            return sortednums[res];
        return 0;
    }
private:
    int k;
    vector<int> sortednums;
};


int main()
{
    int arr[] = {4, 5, 8, 2};
    vector<int> nums(arr, arr+4);
    KthLargest ob(3, nums);
    //[3], [5], [10], [9], [4]
    cout << ob.add(3) << endl;
    cout << ob.add(5) << endl;
    cout << ob.add(10) << endl;
    cout << ob.add(9) << endl;
    cout << ob.add(4) << endl;

    return 0;
}
