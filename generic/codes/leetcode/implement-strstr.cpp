#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void failfunction(string& needle, vector<int>& varray)
    {
        int nsize = needle.size();
        int i = 1;
        int j = 0;
        for (; i < nsize; ++i)
        {
            while ( j>=0 && needle[i] != needle[j])
                j = (j-1 >= 0) ? varray[j-1] : -1;

            ++j;
            varray[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        if (haystack.empty())
            return (needle.empty() ? 0 : -1);
        if (needle.empty())
            return 0;

        int nsize = needle.size();
        vector<int> varray(nsize, 0);
        failfunction(needle, varray);

        int hsize = haystack.size();
        int i = 0, j = 0;
        for( ; i < hsize; ++i)
        {
            while ( j>=0 && haystack[i] != needle[j])
                j = (j-1 >= 0) ? varray[j-1] : -1;
            ++j;
            if (j==nsize)
                return i - nsize+1; 
        }
        return -1;
    }
};

int main()
{
    Solution ob;
    cout << ob.strStr("abcdabeabf","dab") << endl;
    cout << ob.strStr("aabaadcdeababc","ababc") << endl;
    cout << ob.strStr("aabaadcdeababc","dab") << endl;
    cout << ob.strStr("aaaaaaaaaa","aaa") << endl;
    cout << ob.strStr("","") << endl;
    cout << ob.strStr("ab","") << endl;
    cout << ob.strStr("","ab") << endl;

    return 0;
}