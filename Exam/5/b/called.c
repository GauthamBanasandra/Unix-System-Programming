#include <stdio.h>
#include <signal.h>
void hdlr_alrm(int);

int main()
{
	printf("child pid=%d\n", getpid());
	signal(SIGALRM, hdlr_alrm);
	
	pause();
}
