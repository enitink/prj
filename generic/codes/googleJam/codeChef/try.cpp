#include<iostream>

using namespace std;

int mod( string b, int a )
{
	int r = 0;
	for(int i=0;i<b.size(); i++ )
	{ 
		r=(r*10 + b[i] - '0')%a ; 
	}
	return r;
}

bool iszero(string b)
{
	for(int i=0; i < b.length(); i++ ) if( b[i] != '0' ) return false;

	return true;
}

int gcd( int a, int b )

{

int tmp;

int shift=0;

while( a!=0 )

{

if( a > b ){tmp=a;a=b;b=tmp;}

bool ao=(a&1);

bool bo=(b&1);

if(ao&&bo){tmp=a; a=(b-a)>>1; b=tmp;}

else if(ao){ b = b>>1; }

else if(bo){ a = a>>1; }

else {a=a>>1;b=b>>1;++shift;}

}

return b<<shift;

}

main()

{

int t , a;

string b;

cin>>t;

while( t-- > 0 )

{

cin>>a>>b;

if(a==0)

cout<<b<<endl;

else if(iszero(b))

cout<<a<<endl;

else

{

int x=mod(b,a);

cout<<gcd(x,a)<<endl;

}

}

}
