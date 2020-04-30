#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int expandPalindrome(const string &s, int left, int right)
    {
        int len = s.length();
        if (len <= 0 || left > right) return 0;

        while( (left >=0) && (right < len) && (s[left] == s[right]) )
        {
            --left;
            ++right;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int len = s.length();
        if (0 == len)
            return "";
        int start = 0;
        int maxlen = 0;

        for(int i=0;i<len;++i)
        {
            int len1 = expandPalindrome(s, i, i); //For odd number of 
            int len2 = expandPalindrome(s, i, i+1);
            int llen = (len1 > len2) ? len1 : len2;
            if (llen > maxlen)
            {
                    start = i - ((llen-1)/2);
                    maxlen = llen;
            }
        }

        return s.substr(start, maxlen);
    }
};

int main()
{
    Solution ob;
     //cout << endl << ob.longestPalindrome("klvxwqyzugrdoaccdafdfrvxiowkcuedfhoixzipxrkzbvpusslsgfjocvidnpsnkqdfnnzzawzsslwnvvjyoignsfbxkgrokzyusxikxumrxlzzrnbtrixxfioormoyyejashrowjqqzifacecvoruwkuessttlexvdptuvodoavsjaepvrfvbdhumtuvxufzzyowiswokioyjtzzmevttheeyjqcldllxvjraeyflthntsmipaoyjixygbtbvbnnrmlwwkeikhnnmlfspjgmcxwbjyhomfjdcnogqjviggklplpznfwjydkxzjkoskvqvnxfzdrsmooyciwulvtlmvnjbbmffureoilszlonibbcwfsjzguxqrjwypwrskhrttvnqoqisdfuifqnabzbvyzgbxfvmcomneykfmycevnrcsyqclamfxskmsxreptpxqxqidvjbuduktnwwoztvkuebfdigmjqfuolqzvjincchlmbrxpqgguwuyhrdtwqkdlqidlxzqktgzktihvlwsbysjeykiwokyqaskjjngovbagspyspeghutyoeahhgynzsyaszlirmlekpboywqdliumihwnsnwjc");
     //cout << endl << ob.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    // cout << endl << ob.longestPalindrome("babad");
     cout << endl << ob.longestPalindrome("aabba");
    // cout << endl << ob.longestPalindrome("a a");

    cout << endl;

    return 0;
}