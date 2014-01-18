#ifndef _COMMON_DEFS_H_
#define _COMMON_DEFS_H_

namespace gen { namespace common { namespace defs {

typedef struct
{	unsigned n : 4; }	u4_t;
typedef unsigned long	u32_t; 
typedef signed 	 long	s32_t; 

#define handle_error(msg) \
		do { perror(msg); exit(EXIT_FAILURE); } while (0)

}}}
#endif //_COMMON_DEFS_H_
