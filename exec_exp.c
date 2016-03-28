#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void show();

int main()
{
	atexit(show);
	fork();
	printf("in main\n");	
	return 0;
}

void show()
{
	printf("in show\n");
}

void show_exec()
{
	printf("in show_exec\n");
}
