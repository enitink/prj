/*
Problem			:	code for finding LCM of.. n consicutive nos (2 <= n <= 100)
Explaination	:	Finds for each prime number less then n, the max power of which
					can be less then n. eg. n = 10, max power of 2 can be 3, so 8.
					Then, for 3 can be 2, so 9. Power of 5 can be 1, so 5. And power
					of 7 can also just be 1, so 7. Answer will be.. 8*9*5*7 = 2520
*/
int Primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int lcmOfNumbersTill(int n)
{
	int i, p, tp;
	unsigned long int res;
	i = 0;
	res = 1;
	while((Primes[i] <= n) && (i < 25)){
		tp = p = Primes[i];
		++i;
		while(p <= n){
			p *= tp;
		}
		if(p > n)
			p /= tp;
		res *= p;
	}
	return res;
}
