#include <cctype>      
#include <cstring>    

#include "hugeint1.h"  

HugeInt::HugeInt( long value )
{
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;   

  for ( int j = 29; value != 0 && j >= 0; j-- ) {
      integer[ j ] = value % 10;
      value /= 10;

   }
}

HugeInt::HugeInt( const char *string )
{
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   int length = strlen( string );

   for ( int j = 30 - length, k = 0; j <= 29; j++, k++ )

      if ( isdigit( string[ k ] ) )
         integer[ j ] = string[ k ] - '0';

}

HugeInt HugeInt::operator+( const HugeInt &op2 )
{
   HugeInt temp; 
   int carry = 0;

   for ( int i = 29; i >= 0; i-- ) {
      temp.integer[ i ] = 
         integer[ i ] + op2.integer[ i ] + carry;

      if ( temp.integer[ i ] > 9 ) {
         temp.integer[ i ] %= 10;  
         carry = 1;

      }
      else
         carry = 0;
   }

   return temp;

}

HugeInt HugeInt::operator+( int op2 )
{ 
   return *this + HugeInt( op2 ); 
}

HugeInt HugeInt::operator+( const char *op2 )
{ 
   return *this + HugeInt( op2 ); 
}

ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i;

   for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= 29 ); i++ )
      ; 

   if ( i == 30 )
      output << 0;
   else

      for ( ; i <= 29; i++ )
         output << num.integer[ i ];

   return output;
}

