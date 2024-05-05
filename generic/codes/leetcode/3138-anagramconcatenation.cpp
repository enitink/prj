class Solution {
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    int minAnagramLength(string s) {
        int slen = s.length();
        int arr[26] = {};
        int i = 0;
        int maxsize = 0;
        for(i=0; i<slen; ++i)
        {
            arr[s[i] - 'a']++;
            maxsize = (arr[s[i] - 'a'] > maxsize) ? arr[s[i] - 'a'] : maxsize;
        }
        int lgcd = gcd(arr[0], arr[1]);
        //cout << endl << lgcd;

        for (i=2; i<26; ++i)
        {
            if (arr[i])
                lgcd = gcd(lgcd, arr[i]);
        }
        //cout << endl << lgcd;

        for(i=0;i<26;++i)
        {
            if (arr[i])
                arr[i] /= lgcd;
        }
        int result = 0;
        for(i=0;i<26;++i)
        {
            if (arr[i])
                result += arr[i];
        }
        return result;
    }
};