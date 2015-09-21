#include <stdio.h>

#define ifcheck(u,v,w,x,y,z) if(res == 0) \
							 { \
							 	if( ((u+w) <= y) &&  ((v <= z) && (x <= z)) )\
							 	{\
							 		res = 1;\
							 	}\
							 }
int main()
{
    int n, m, a, b, c, d, res = 0;
    scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
    
    ifcheck(a,b,c,d,m,n)
    ifcheck(a,b,c,d,n,m)
    ifcheck(a,b,d,c,m,n)
    ifcheck(a,b,d,c,n,m)
    ifcheck(b,a,d,c,m,n)
    ifcheck(b,a,d,c,n,m)
    ifcheck(b,a,c,d,m,n)
    ifcheck(b,a,c,d,n,m)
    
    if ( res )
    	printf("Yes");
    else
    	printf("No");
    return 0;
}
