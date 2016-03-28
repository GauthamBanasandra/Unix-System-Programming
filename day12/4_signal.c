#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void myhandler(int signo)
{
	printf("signal # : %d\n", signo);
}
int main()
{
	sigset_t sigset1;
	sigset_t oldset;
	sigset_t pendset;
	sigemptyset(&sigset1);
	sigaddset(&sigset1, SIGINT);
	sigaddset(&sigset1, SIGQUIT);

	if(signal(SIGINT, myhandler) == SIG_ERR)
	{
		perror("signal"); exit(1);
	}
	if(signal(SIGQUIT, myhandler) == SIG_ERR)
	{
		perror("signal"); exit(1);
	}
	printf("program starts\n");
	sleep(20);
	// block signals
	if(sigprocmask(SIG_BLOCK , &sigset1, &oldset) == -1)
	{
		perror("blocking signals"); exit(1);
	}
	// enter critical section
	printf("entering critical section\n");
	sleep(20);
	// check pending signals
	if(sigpending(&pendset) == -1)
	{
		perror("pending signals"); exit(1);
	}
	// identify the signal that was pending
	if(sigismember(&pendset, SIGINT))
	{
		printf("SIGINT pending\n");

	}
	if(sigismember(&pendset, SIGQUIT))
	{
		printf("SIGQUIT pending\n");

	}
	sleep(20);
	// end critical section
	printf("exiting critical section\n");
	
	if(sigprocmask(SIG_SETMASK , &oldset, NULL) == -1)
	{
		perror("unblocking signals"); exit(1);
	}

	sleep(20);
	printf("program terminates\n");
}
