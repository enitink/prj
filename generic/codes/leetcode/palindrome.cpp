#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s)
    {
        int len = s.length();
        if (len == 2)
                 return (s[0] == s[1]);
        if (len == 1)
            return true;
        
        map<string,bool>::iterator it =  mymap.find(s);
        if (it != mymap.end())
        {
            return it->second;
        }

        bool res = false;
        
        if (s[0] == s[len-1])
            res = isPalindrome(s.substr(1, len - 2));
        
        mymap[s] = res;

        return res;
    }
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int i = 0;
        int j = 0;
        int resultLength = 0;
        string result = "";
        int len = s.length();
        for(;i<len && (len -i > resultLength);++i)
        {
            for(j=1; j<=(len-i); ++j)
            {
                string substring = s.substr(i,j);
                if (isPalindrome(substring))
                {
                    if (resultLength < j)
                    {
                        resultLength = j;
                        result = substring;
                    }
                }                
            }
        }
        if (resultLength == 0)
            result = s[i];

        return result;
    }
private:
    map<string, bool> mymap;
};

int main()
{
    Solution ob;
     //cout << endl << ob.longestPalindrome("klvxwqyzugrdoaccdafdfrvxiowkcuedfhoixzipxrkzbvpusslsgfjocvidnpsnkqdfnnzzawzsslwnvvjyoignsfbxkgrokzyusxikxumrxlzzrnbtrixxfioormoyyejashrowjqqzifacecvoruwkuessttlexvdptuvodoavsjaepvrfvbdhumtuvxufzzyowiswokioyjtzzmevttheeyjqcldllxvjraeyflthntsmipaoyjixygbtbvbnnrmlwwkeikhnnmlfspjgmcxwbjyhomfjdcnogqjviggklplpznfwjydkxzjkoskvqvnxfzdrsmooyciwulvtlmvnjbbmffureoilszlonibbcwfsjzguxqrjwypwrskhrttvnqoqisdfuifqnabzbvyzgbxfvmcomneykfmycevnrcsyqclamfxskmsxreptpxqxqidvjbuduktnwwoztvkuebfdigmjqfuolqzvjincchlmbrxpqgguwuyhrdtwqkdlqidlxzqktgzktihvlwsbysjeykiwokyqaskjjngovbagspyspeghutyoeahhgynzsyaszlirmlekpboywqdliumihwnsnwjc");
     cout << endl << ob.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    // cout << endl << ob.longestPalindrome("babad");
     cout << endl << ob.longestPalindrome("acbbbca");
    // cout << endl << ob.longestPalindrome("a a");

    cout << endl;

    return 0;
}