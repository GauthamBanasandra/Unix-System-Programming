// read the output of ls; display it on the screen
//	popen
// send the input to wc -l from this program
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	FILE* fin;
	FILE* fout;
	char line[80];
	fin = popen("ls", "r"); // mode can be r or w
	fout = popen("wc -l", "w");
	while(fscanf(fin, "%s\n", line) > 0)
	{
		fprintf(fout, "%s\n", line);
	}
	pclose(fin);
	pclose(fout);
}


