#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include "err.h"
struct message
{
	long type;
	char text[20];
};

int main()
{
	int id;
	(id=msgget(ftok("/home/gautham/Downloads/faulkner.jpg", 'A'), IPC_CREAT|0666))==-1?err("msgget"):0;
	struct message m;
	strcpy(m.text, "some data");
	m.type=1;
	msgsnd(id, (void*)&m, sizeof(m)-sizeof(long), 0)==-1?err("msgsnd"):0;
	return 0;
}
