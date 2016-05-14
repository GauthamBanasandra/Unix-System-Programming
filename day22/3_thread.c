// example with no racing
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* foo(void* p)
{
	char *s = (char*)p;
//	printf("------\n");
	char ch;
	while(ch = *s++)
	{
		sem_wait(&sem);;
		putchar(ch);
		fflush(stdout);
		sleep(rand() % 3);
		putchar(ch);
		fflush(stdout);
		sem_post(&sem);
		sleep(rand() % 3);
	}
//	printf("*******\n");
}
int  main()
{
	sem_init(&sem, 0, 1); // not shared; init value 1
	srand(getpid());
	pthread_t t1;
	pthread_t t2;
//	printf("one\n");
	pthread_create(&t1, 0, foo, (void*)"ABCDEFGH");
	pthread_create(&t2, 0, foo, (void*)"abcdefgh");
//	printf("two\n");
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	sem_destroy(&sem);
	pthread_exit(0);
//	printf("three\n"); // not reachable
}
