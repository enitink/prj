#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int lent = temperatures.size(), i = 1;
        vector<int> result(lent, 0);
        if (lent == 0) return result;
        stack<int> st;
        st.push(0);
        for( ; i<lent; ++i)
        {
            while (temperatures[st.top()] < temperatures[i])
            {
                int pos = st.top();
                result[pos] = i - pos;
                st.pop();
                if (st.empty())
                    break;
            }
            st.push(i);
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        int arr[] = {73,74,75,71,69,72,76,73};
        vector<int> nums(arr, arr+8);
        vector<int> result = ob.dailyTemperatures(nums);
        int rlen = result.size(), i;
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    {
        int arr[] = {30,40,50,60};
        vector<int> nums(arr, arr+4);
        vector<int> result = ob.dailyTemperatures(nums);
        int rlen = result.size(), i;
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    {
        int arr[] = {30,60,90};
        vector<int> nums(arr, arr+3);
        vector<int> result = ob.dailyTemperatures(nums);
        int rlen = result.size(), i;
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}