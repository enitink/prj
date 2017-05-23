#include <stdio.h>

// check what file is produced when you run cl macro_for_swap.cpp /P Open // the file and analyze
// Excercise -- can you do the same operation using unions? 


typedef union
{
    unsigned int val;
    struct swaphelper
    {
        short int firsthalf;
        short int secondhalf;
    }s;

}toswap;

//#define DISPLACE(x)  ( (x >>16) | (x<<16) )
#define DISPLACE(X) ( (unsigned int)X.s.secondhalf << 16 | (unsigned int)X.s.firsthalf )

int main()
{
              unsigned int TestInt = 0xEEEEFFFF;
              toswap TestVal;
              TestVal.val = TestInt;
              unsigned int ExpectedResult = 0xFFFFEEEE;

              printf( "Sizeof(short int) = %d & Sizeof(int) = %d\n", sizeof(short int), sizeof(int) );

              unsigned int UsingMacrosResult = DISPLACE( TestVal ) ;

              printf( " TestInt = %x, ExpectedRestult = %x, ActualResult = %x\n",TestInt , ExpectedResult , UsingMacrosResult );
              

}
