#include <stdio.h>
#include <pthread.h>
#define ARR_SIZE 20
void *sum_array(void *);
void verify();

int sum;
int num[ARR_SIZE];
struct tparam
{
	int start;
	int stop;
};
pthread_mutex_t lock;

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("format: <prg> [num of threads]\n");
		return;
	}
	if(atoi(argv[1])>ARR_SIZE)
	{
		printf("error: MAX_THREADS=%d\n", ARR_SIZE);
		return;
	}
	
	srand((unsigned)time(NULL));
	
	register int i;
	for(i=0; i<sizeof(num)/sizeof(int); ++i)
		num[i]=rand()%50;	
		
	int threads=atoi(argv[1]);
	
	pthread_t tid[threads];
	struct tparam param[threads];
	int block=sizeof(num)/(sizeof(int)*threads);
	pthread_mutex_init(&lock, NULL);
	
	for(i=0; i<threads; ++i)
	{		
		param[i].start=i*block;
		param[i].stop=(i==threads-1)?sizeof(num)/sizeof(int):(i+1)*block;
		pthread_create(&tid[i], NULL, sum_array, (void *)&param[i]);
	}
	
	for(i=0; i<threads; ++i)
		pthread_join(tid[i], NULL);
	
	printf("efficient sum=%d\n", sum);
	verify();
	
	pthread_mutex_destroy(&lock);
	
	return 0;	
}

void *sum_array(void *vargp)
{
	struct tparam *param=(struct tparam *)vargp;
	register int i;
	int _sum=0;
	
	for(i=param->start; i<param->stop; ++i)
		_sum+=num[i];
	
	
	pthread_mutex_lock(&lock);
	sum+=_sum;
	pthread_mutex_unlock(&lock);
}

void verify()
{
	int _sum=0;
	register int i;
	for(i=0; i<sizeof(num)/sizeof(int); ++i)
		_sum+=num[i];
	
	printf("linear sum=%d\n", sum);
}
