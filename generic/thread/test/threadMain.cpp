#include 	<iostream>
#include 	<cstdlib>
#include 	<pthread.h>
#include 	<ServerThreadImpl.h>

using std::cout;
using std::endl;
using std::cin;

//using Thread class

int main()
{
	ServerThreadImpl obj;
	exit(0);
}

/*
void* thrdFunc(void* id) {
	static int i;
	sleep(1);
	for (;;)
		cout << endl << i++;
	return NULL;
}

int
main(int argc, char **argv){
	
	pthread_t 	thread;
	void *status;

	pthread_create(&thread, NULL, thrdFunc, NULL);
	pthread_join(thread, &status);
	
	exit(0);
}
*/
/*

#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}

int main ()
{
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   for( i=0; i < NUM_THREADS; i++ ){
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, 
                          PrintHello, (void *)i);
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
*/
