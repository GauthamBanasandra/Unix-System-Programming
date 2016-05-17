#include <stdio.h>
#include <unistd.h>
#include "../../utils/utils.h"
void print_char(int, int);

int main()
{
	pid_t pid;
	int i;
	
	if(pid=fork())
		print_char(65, 90);
	else
		print_char(97, 122);
			
	return 0;
}
