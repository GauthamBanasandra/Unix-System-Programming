// example with no racing
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t m;

void* foo(void* p)
{
	char *s = (char*)p;
//	printf("------\n");
	char ch;
	while(ch = *s++)
	{
		pthread_mutex_lock(&m);
		putchar(ch);
		fflush(stdout);
		sleep(rand() % 3);
		putchar(ch);
		fflush(stdout);
		pthread_mutex_unlock(&m);
		sleep(rand() % 3);
	}
//	printf("*******\n");
}
int  main()
{
	pthread_mutex_init(&m, 0);
	srand(getpid());
	pthread_t t1;
	pthread_t t2;
//	printf("one\n");
	pthread_create(&t1, 0, foo, (void*)"ABCDEFGH");
	pthread_create(&t2, 0, foo, (void*)"abcdefgh");
//	printf("two\n");
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	pthread_mutex_destroy(&m);
	pthread_exit(0);
//	printf("three\n"); // not reachable
}
