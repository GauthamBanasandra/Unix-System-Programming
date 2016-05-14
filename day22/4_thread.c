// example with no racing; alternate exactly
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1;
sem_t sem2;

void* foo1(void* p)
{
	char *s = (char*)p;
//	printf("------\n");
	char ch;
	while(ch = *s++)
	{
		sem_wait(&sem1);;
		putchar(ch);
		fflush(stdout);
		sleep(rand() % 3);
		putchar(ch);
		fflush(stdout);
		sem_post(&sem2);
		sleep(rand() % 3);
	}
//	printf("*******\n");
}

void* foo2(void* p)
{
	char *s = (char*)p;
//	printf("------\n");
	char ch;
	while(ch = *s++)
	{
		sem_wait(&sem2);;
		putchar(ch);
		fflush(stdout);
		sleep(rand() % 3);
		putchar(ch);
		fflush(stdout);
		sem_post(&sem1);
		sleep(rand() % 3);
	}
//	printf("*******\n");
}
int  main()
{
	sem_init(&sem1, 0, 1); // not shared; init value 1
	sem_init(&sem2, 0, 0);
	srand(getpid());
	pthread_t t1;
	pthread_t t2;
//	printf("one\n");
	pthread_create(&t1, 0, foo1, (void*)"ABCDEFGH");
	pthread_create(&t2, 0, foo2, (void*)"abcdefgh");
//	printf("two\n");
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	sem_destroy(&sem1);
	sem_destroy(&sem2);

	pthread_exit(0);
//	printf("three\n"); // not reachable
}
