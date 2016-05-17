#include <stdio.h>
#include <signal.h>
#include "../../utils/utils.h"
void hdlr_alrm(int);

int main()
{
	sigset_t blkset;
	
	if(sigemptyset(&blkset)==-1)
		error("unable to initialize sigset");
		
	if(sigaddset(&blkset, SIGINT)==-1)
		error("unable to add SIGINT to set");
		
	if(sigprocmask(SIG_BLOCK, &blkset, NULL)==-1)
		error("unable to block SIGINT");
	
	if(signal(SIGALRM, hdlr_alrm)==SIG_ERR)
		error("unable to register alarm");
	alarm(5);
	printf("execing in 5 seconds\nyou may start signalling now\n");
	
	while(1);
	return 0;
}
