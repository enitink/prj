#include <stdio.h>
#include <arpa/inet.h>


int main()
{
	unsigned int some_long = 67;
	unsigned short some_short = 4172;

	// convert and send
	//network_byte_order = htons(some_long);
	//some_short == ntohs(htons(some_short)); // this expression is true

	printf("%d %x %x %d", htons(some_long), htons(some_long), htons(some_short), htons(some_short));
	return 0;
}
