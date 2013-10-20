#include <stdio.h>

#define BUILD_FIELD(field) ac.##field
#define PRINT_TOKEN(token) printf(#token " is %d", token)

struct abc{
	int a;
	int b;
};

int main(){
	struct abc ac;
	int d = 10;

	ac.a = 10;
	ac.b= 20;

	PRINT_TOKEN(d);
	printf("\n%d", BUILD_FIELD(a));	

	return 0;
}
