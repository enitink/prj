#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if ((sLen == 0 || tLen == 0) || (sLen < tLen)) {
            return "";
        }

        int freq[128] = {0}, tuniqcount = 0, suniqcount = 0;
        for (char c : t) {
            freq[c]++;
            if (freq[c] == 1) {
                tuniqcount++;
            }
        }
        int st = 0, en = 0, minlen = INT_MAX, minst = 0;
        int sfreq[128] = {0};
        for (int i = 0; i < sLen; i++) {
            if (freq[s[i]] == 0)
                continue;
            sfreq[s[i]]++;
            if (sfreq[s[i]] == freq[s[i]])
                suniqcount++;
            if (suniqcount == tuniqcount)
            {
                while (freq[s[st]] == 0 || sfreq[s[st]] > freq[s[st]]) {
                    if (sfreq[s[st]] > freq[s[st]]) {
                        sfreq[s[st]]--;
                    }
                    st++;
                }
                int llen = i - st + 1;
                if (llen < minlen) {
                    minlen = llen;
                    minst = st;
                }
            }
        }
        if (minlen == INT_MAX) {
            return "";
        }
        return s.substr(minst, minlen);
    }
};

int main()
{
    Solution sol;
    {
        string s = "ADOBECODEBANC";
        string t = "ABC";
        cout << sol.minWindow(s, t) << endl;
    }
    {
        string s = "a";
        string t = "a";
        cout << sol.minWindow(s, t) << endl;
    }
    {
        string s = "a";
        string t = "aa";
        cout << sol.minWindow(s, t) << endl;
    }
    {
        string s = "a";
        string t = "b";
        cout << sol.minWindow(s, t) << endl;
    }
    return 0;
}


/*
int sLen = s.size();
        int tLen = t.size();
        if ((sLen == 0 || tLen == 0) || (sLen < tLen)) {
            return "";
        }

        int freq[128] = {0}, tuniqcount = 0, suniqcount = 0;
        for (char c : t) {
            freq[c]++;
            if (freq[c] == 1) {
                tuniqcount++;
            }
        }
        int s = 0, e = 0, i = 0;
        for ( ;i<sLen; i++) {
            if (freq[s[i]] == 0)
                continue;
            break;
        }
        if (i == sLen) {
            return "";
        }
        int st = i, en = i;
        int sfreq[128] = {0};
        for ( ;i<sLen; i++) {
            if (freq[s[i]] == 0)
                continue;
            sfreq[s[i]]++;
            if (sfreq[s[i]] == freq[s[i]])
                suniqcount++;
            if (suniqcount == tuniqcount)
            {
                
                int llen = i - st + 1;
                if (llen > (en - st + 1)) {
                    st = st;
                    en = i;
                }
            }

        }
*/