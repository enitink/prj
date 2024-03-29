#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        int slen = s.length();
        int tlen = t.length();
        if (slen != tlen)
            return false;

        int i = 0;
        for( ;i<slen; ++i)
        {
            arr[s[i] - 'a']++;
        }
        for (i=0; i<tlen; ++i)
        {
            arr[t[i] - 'a']--;
            if ((arr[t[i] - 'a']) < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution ob;
    cout << ob.isAnagram("anagram", "nagaram") << endl;
    cout << ob.isAnagram("car", "rat") << endl;

    return 0;
}