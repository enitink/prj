class Solution {
    
    int expandPalindrome(const string &s, int left, int right)
    {
        int len = s.length();
        if (len <= 0 || left > right) return 0;
        
        int count = 0;

        while( (left >=0) && (right < len) && (s[left] == s[right]) )
        {
            --left;
            ++right;
            ++count;
        }

        return count;
    }

public:
    int countSubstrings(string s) {
        int len = s.length();
        int count = 0;
        for(int i=0;i<len;++i)
        {
            int count1 = expandPalindrome(s, i, i);
            int count2 = expandPalindrome(s, i, i+1);
            count += (count1 + count2);
        }
        return count;
    }
};