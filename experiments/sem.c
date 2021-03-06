#include <stdio.h>
#include <pthread.h>
void * lower_case(void *);
void * upper_case(void *);
char c='A';

int main()
{
	pthread_t tid1, tid2;
	
	pthread_create(&tid1, NULL, lower_case, NULL);
	pthread_create(&tid2, NULL, upper_case, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	return 0;
}

void * lower_case(void *x)
{	
	printf("lower case\n");
	printf("%c\n", c);
	while(c+32<123)
		printf("%c\n", c);
	printf("lower case end\n");
}

void * upper_case(void *x)
{
	printf("upper case\n");
	while(c++<91)
		printf("%c\n", c);
	printf("upper case end\n");
}
