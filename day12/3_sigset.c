#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	sigset_t x;
	// always call sigemptyset() to clear the default values
	sigemptyset(&x);
	// adding SIGINT to sigset
	sigaddset(&x, 2);
	// checking if a signal exists
	printf("2 ? %d\n", sigismember(&x, 2));
	printf("3 ? %d\n", sigismember(&x, 3));
}
