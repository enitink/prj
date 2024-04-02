#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int slen = s.length();
        int i = 0;
        std::string nstr = "";
        for( ; i<slen; ++i)
        {
            if ( (s[i] >= '0') && (s[i] <= '9') )
            { 
                nstr += s[i];
            }
            else if ( ( (s[i]|32) >= 'a') && ( (s[i]|32) <= 'z'))
            {   
                nstr += (s[i] | 32);
            }
        }
        slen = nstr.length();
        for(i=0; i<slen/2; ++i)
        {
            if (nstr[i] != nstr[slen-i-1])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution ob;

    std::cout << (ob.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false");
    std::cout << std::endl << (ob.isPalindrome("race a car") ? "true" : "false");
    std::cout << std::endl << (ob.isPalindrome("a1 b1 1b 1a") ? "true" : "false");
    std::cout << std::endl << (ob.isPalindrome("a1 b1 cc 1b 1a") ? "true" : "false");
    std::cout << std::endl << (ob.isPalindrome("a") ? "true" : "false");
    std::cout << std::endl << (ob.isPalindrome("1") ? "true" : "false");
    std::cout << std::endl << (ob.isPalindrome("") ? "true" : "false");

    return 0;
}