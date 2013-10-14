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

}}} //gen::common::utils namespace ends
#endif //_COMMON_UTILS_H_
