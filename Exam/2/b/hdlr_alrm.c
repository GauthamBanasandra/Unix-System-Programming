#include <stdio.h>
#include <unistd.h>
#include "../../utils/utils.h"

void hdlr_alrm(int signo)
{
	printf("alarm received\n");

	if(execl("called", "arg", NULL)==-1)
		error("unable to exec");
}
