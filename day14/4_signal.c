#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <errno.h>
char a[21] = "zyx";

void handler(int signo)
{
	sigset_t s;
	if(sigprocmask(0, 0, &s) == -1)
	{
		perror("sigprocmask"); exit(1);
	}
	if(sigismember(&s, SIGALRM))
	{
		printf("sigalrm is blocked\n");
	}
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
	sigset_t s;
	if(sigprocmask(0, 0, &s) == -1)
	{
		perror("sigprocmask"); exit(1);
	}
 	if(sigismember(&s, SIGALRM))
	{
		printf("sigalrm is blocked\n");
	}
	else
	{
		printf("sigalrm is not blocked\n");
	}


}


