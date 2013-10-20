#include <cstdarg>
#include <iostream>

using namespace std;

double average ( int num, ... )
{
  va_list arguments;                     // A place to store the list of arguments
  double sum = 0;

  va_start ( arguments, num );           // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    sum += va_arg ( arguments, double ); // Adds the next value in argument list to sum.
  va_end ( arguments );                  // Cleans up the list

  return sum / num;                      // Returns some number (typecast prevents truncation)
}
int main()
{
  cout<< average ( 3, 12.2, 22.3, 4.5 ) <<endl;
  cout<< average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) <<endl;
}
