#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

int main()
{
	int id;
	id=msgget(ftok("/home/gautham/Downloads/faulkner.jpg", 'A'), IPC_CREAT|0664);
	printf("id=%d\n", id);
	return 0;
}
