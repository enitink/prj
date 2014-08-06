//eg: taken from http://www.cplusplus.com/reference/mutex/mutex/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

std::mutex mtx;           // mutex for critical section

void*                     /* Thread start function */
tfunc(void* arg)
{
  // critical section (exclusive access to std::cout signaled by locking mtx):
  mtx.lock();
  for (int i=0; i<20; ++i) { std::cout << *arg; }
  std::cout << '\n';
  mtx.unlock();
}

int main ()
{
	char s = '*';
	char d = '$'';
	pthread_t       _threadId;
	pthread_create(&_threadId, NULL, tfunc, &s);
	pthread_join(_threadId, NULL);
	
	pthread_t       _threadIdO;
	pthread_create(&_threadIdO, NULL, tfunc, &d);
	pthread_join(_threadIdO, NULL);

  	return 0;
}
