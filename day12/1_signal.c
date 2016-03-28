// low level communication mechanism
// send an int to another process
// kill -l : list of signals

// how to send a signal?
// what happens when a signal is received?
// is it possible to block signals?
//	can we restore receiving the signals?
// if signals are received when blocked, are they lost?
//		if not, can we check what is kept waiting?
// what happens on fork?
// what happens on exec?


/* Generating a signal
	1. send a signal from the terminal
		SIGINT
		SIGQUIT : generates a core
	2. use kill command of the shell
		kill -<signo> <pid>
	3. use kill system call - programmatically
	4. hardware generated signals
		SIGSEGV
	5. software generated signals
		SIGALRM (timer)
	
*/

// How does a process react on being signaled?
//	a) take default action
//			most of the cases : terminates the process
//	b) ignore it
//	c) pass the control to a handler
//		asynchroneous


// lang theory:
//	transfer of control :
//		macro
//		goto stmt
//		setjmp and longjmp
//		fn call
//		thread
//		co-routine
//		exception
//			signal

// data structure in u-area
// a) signal disposition
//		array of pointers to functions
//			entry in each : pointer to a function with a particular signature
//							SIG_DFL
//							SIG_IGN
// b) pending signals
//		a bit for each signal
//		type : sigset_t
//
// c) blocking signals
//		a bit for each signal
//		type : sigset_t

// there are two signals which can neither be ignored nor handled
//		SIGKILL
//		SIGSTOP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void myhandler(int signo)
{
	printf("recd signal number : %d\n", signo);
	getchar(); getchar();
}

int main()
{
	if(signal(SIGINT, myhandler) == SIG_ERR)
	{
		perror("signal"); exit(1);
	}
	while(1)
	{
		printf("hello world\n");
	}
}














































