#include <iostream>


class Solution {
public:
    int reverse(int x) {
        int neg = (x < 0) ? -1 : 1;
        long int res = 0;
        res = x;
        res *= neg;
        if (res > 2147483647)
            return 0;
        res = 0;
        x *= neg;
        
        while(x)
        {
            res = (res * 10) + (x % 10);
            x /= 10;
        }
        if (res > 2147483647)
            return 0;
        return res * neg;
    }
};

int main()
{
    Solution ob;

    std::cout << ob.reverse(123);
    std::cout << std::endl << ob.reverse(-2147483648);
    std::cout << std::endl << ob.reverse(1534236469);
    std::cout << std::endl << ob.reverse(-10);
    std::cout << std::endl << ob.reverse(1);
    std::cout << std::endl << ob.reverse(-1);

    return 0;
}