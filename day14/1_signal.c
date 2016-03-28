#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <errno.h>
char a[21] = "zyx";

void handler(int signo)
{
	printf("Recd signal # : %d\n", signo);
	putchar(a[0]);
	
}
int main()
{
	int n;
	alarm(5);
	if(signal(SIGALRM, handler) == SIG_ERR)
	{
		perror("sigalrm"); exit(1);
	}
	if( (n = read(0, a, 20)) == -1)
	{
		if(errno == EINTR)
		{
			perror("interrupted"); exit(2);
		}
	}
	a[n] = '\0';
	printf("read : %s\n", a);
	
}


