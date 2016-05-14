#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
void* foo(void* junk)
{
	printf("this is a thread fn\n");
}
pthread_t t1;
int main()
{
	printf("one\n");
	pthread_create(&t1, 0, foo, 0);
	printf("two\n");
	pthread_exit(0); // main thread exits; but not the process
}
