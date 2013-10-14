#ifndef _COMMON_UTILS_H_
#define _COMMON_UTILS_H_

namespace gen { namespace common { namespace utils {

template < class T >
bool gSwap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
	return true;
}

bool isPalindromeNumber(int n){
    int tempn = n;
    int rev = 0;
    int rem = 0;

    while(tempn != 0){
        rem = tempn % 10;
        rev = rev * 10 + rem;
        tempn /= 10;
    }
    return (rev == n)? true:false;
}

bool isPrime(long int n){
    long int i;
    for(i = 2; i <= sqrt(n); ++i){
        if( n%i == 0)
            return false;
    }
    return true;
}

}}} //gen::common::utils namespace ends
#endif //_COMMON_UTILS_H_
