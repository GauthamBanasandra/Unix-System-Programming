#include <stdio.h>

void print_char(int i, int j)
{
	for(;i<=j; printf("%c\tpid=%d\n", i++, getpid()))		
		sleep(rand()%2);
}
