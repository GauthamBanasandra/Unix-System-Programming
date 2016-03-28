#include <stdlib.h>
void err(char *s)
{
	perror(s);
	exit(1);
}
