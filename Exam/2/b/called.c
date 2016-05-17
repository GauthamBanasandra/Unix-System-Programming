#include <stdio.h>
#include <signal.h>
#include "../../utils/utils.h"

int main(int argc, char *argv[])
{
	sigset_t pndset;
	
	if(sigemptyset(&pndset)==-1)
		error("unable to initialize pendset");
		
	if(sigpending(&pndset)==-1)
		error("unable to retrieve pending signals");
	
	if(sigismember(&pndset, SIGINT)==1)
		printf("SIGINT is pending\n");
	
	if(sigprocmask(SIG_UNBLOCK, &pndset, NULL)==-1)
		error("unable to unblock SIGINT");
		
	return 0;
}
