#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <bitset>
#include <numeric>
#include <functional>
#include <utility>
#include <limits>
#include <iterator>


using namespace std;

class Solution {
    bool checkall9s(vector<int>& num, int n )
    {
        int i;
        for(i = 0; i < n; ++i)
            if (num[i] != 9)
                return false;
                
        return true;
    }
    void generateNextPalindromeHelper(vector<int>& num, int n )
    {
        int mid = n / 2;
        bool leftsmaller = false;
        int i = mid - 1;

        int j = (n % 2) ? mid + 1 : mid;

        while (i >= 0 && num[i] == num[j])
            i--, j++;
    
        if (i < 0 || num[i] < num[j])
            leftsmaller = true;
    
        while (i >= 0)
        {
            num[j] = num[i];
            j++;
            i--;
        }
        if (leftsmaller == true)
        {
            int carry = 1;
            i = mid - 1;
            if (n % 2 == 1)
            {
                num[mid] += carry;
                carry = num[mid] / 10;
                num[mid] %= 10;
                j = mid + 1;
            }
            else
                j = mid;
            while (i >= 0)
            {
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;
                
                num[j++] = num[i--];
            }
        }
    }

    long generateNextPalindrome(vector<int>& num, int n)
    {
        int i;
        long newnum = 0;
        if (checkall9s(num, n))
        {
            newnum=1;
            for(i = 1; i < n; i++)
                newnum *= 10;
            newnum += 1;
        }
        else
        {
            generateNextPalindromeHelper(num, n);
            for(i = 0; i < n; i++)
                newnum = newnum * 10 + num[i];
        }
        return newnum;
    }
public:
    long long countGoodIntegers(int n, int k) {
        vector<int> num(n, 0);
        long max =  0;
        int i = 0;
        for(i = 0; i < n; ++i)
            max = max * 10 + 9;
        long long count = 0;
        num[0] = num[n-1] = 1;
        long lastnum = 0;
        for(i=0;i<n;++i)
            lastnum = lastnum * 10 + num[i];
        long min = lastnum;
        while((lastnum <= max) && (lastnum >= min))
        {
            if (lastnum % k == 0)
                count++;
            num[n-1]+=1;
            lastnum = generateNextPalindrome(num, n);
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.countGoodIntegers(3, 5) << endl;
    //cout << s.countGoodIntegers(1, 4) << endl;
    //cout << s.countGoodIntegers(5, 6) << endl;
    //cout << s.countGoodIntegers(10, 9) << endl;
    return 0;
}