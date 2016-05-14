#include <stdlib.h>
void error(char *s)
{
	perror(s);
	exit(1);
}
