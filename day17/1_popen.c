// read the output of ls; display it on the screen
//	popen
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	FILE* fin;
	char line[80];
	fin = popen("ls", "r"); // mode can be r or w
	while(fscanf(fin, "%s\n", line) > 0)
	{
		printf("filename : %s\n", line);
	}
	pclose(fin);
}
