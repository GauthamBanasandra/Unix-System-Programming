#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "../../utils/utils.h"
extern char *arg;

void handler(int signo)
{
	printf("interrupted by SIGNO %d\narg=%s", signo, arg);
	if(!strcmp("dfl", arg))
		if(signal(SIGINT, SIG_DFL)==SIG_ERR)
			error("unable to set handler to default");

	if(!strcmp("ign", arg))
		if(signal(SIGINT, SIG_IGN)==SIG_ERR)
			error("unable to set handler to ignore");
}
