// example with racing
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
void* foo(void* p)
{
	char *s = (char*)p;
//	printf("------\n");
	char ch;
	while(ch = *s++)
	{
		putchar(ch);
		fflush(stdout);
		sleep(rand() % 3);
		putchar(ch);
		fflush(stdout);
		sleep(rand() % 3);
	}
//	printf("*******\n");
}
int  main()
{
	srand(getpid());
	pthread_t t1;
	pthread_t t2;
//	printf("one\n");
	pthread_create(&t1, 0, foo, (void*)"ABCDEFGH");
	pthread_create(&t2, 0, foo, (void*)"abcdefgh");
//	printf("two\n");
	pthread_exit(0);
//	printf("three\n"); // not reachable
}
