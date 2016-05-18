#include <stdio.h>
#include <stdlib.h>

void hdlr_alrm(int signo)
{
	printf("alarm received by %d\n", getpid());
	exit(1);
}
