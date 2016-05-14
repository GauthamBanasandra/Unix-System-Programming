#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
// producer - consumer 
#define SIZE 10
int queue[SIZE + 1];
int r = 0;
int f = 0;
int over = 0;
pthread_mutex_t m;
pthread_cond_t c;
 
void enqueue(int n)
{
	queue[++r] = n;
}
int dequeue()
{
	return queue[++f];
}

int q_empty()
{
	return f == r;
}
void* producer(void* p)
{
	int n = *(int*)p;
	for(int i = 0; i < n; ++i)
	{
		sleep(2);
		pthread_mutex_lock(&m);
		
		enqueue(i * i);
		pthread_cond_signal(&c);
		pthread_mutex_unlock(&m);
	}
	pthread_mutex_lock(&m);
	over = 1;
	pthread_mutex_unlock(&m);

}

void* consumer()
{
	int res;
	
	pthread_mutex_lock(&m);
	while(!over || ! q_empty())
	{
		pthread_mutex_unlock(&m);
		// ...
		pthread_mutex_lock(&m);
		while(q_empty())
		{
			pthread_cond_wait(&c, &m);
		}
		res = dequeue();
		pthread_mutex_unlock(&m);
	
		// do something with the result
		printf("res : %d\n", res);
	}
}
int main()
{
	int n = 10;
	pthread_mutex_init(&m, 0);
	pthread_cond_init(&c, 0);
 	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, 0, producer, (void*)&n);
	pthread_create(&t2, 0, consumer, 0);

	pthread_join(t1, 0);
	pthread_join(t2, 0);

	pthread_exit(0);
}
