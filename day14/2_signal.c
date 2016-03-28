#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <errno.h>
char a[21] = "zyx";
int n;

#if 0
          struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
#endif

void handler(int signo)
{
	printf("Recd signal # : %d\n", signo);
	putchar(a[0]);
	
}
int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if(sigaction(SIGALRM, &sa, 0) == -1)
	{
		perror("sigaction "); exit(3);
	}
	alarm(5);

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


