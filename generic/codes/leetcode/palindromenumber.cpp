#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;
        if ( x < 0 || (x % 10 == 0) )
            return false;
        long int rev = 0;
        long int tx = x;
        while(x)
        {
            rev = rev * 10 + (x%10);
            x /= 10;
        }
        if (tx == rev)
            return true;
        return false;
    }
};

int main()
{
    Solution ob;

    //std::cout << (ob.isPalindrome(2122222217) ? "true" : "false");
    // std::cout << std::endl << (ob.isPalindrome(-121)  ? "true" : "false");
     std::cout << std::endl << (ob.isPalindrome(0)  ? "true" : "false");
    // std::cout << std::endl << (ob.isPalindrome(10)  ? "true" : "false");
    // std::cout << std::endl << (ob.isPalindrome(01)  ? "true" : "false");
    // std::cout << std::endl << (ob.isPalindrome(121)  ? "true" : "false");
    // std::cout << std::endl << (ob.isPalindrome(121)  ? "true" : "false");

    return 0;
}