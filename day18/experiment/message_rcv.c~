#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
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
	m.type=1;
	msgrcv(id, (void*)&m, sizeof(m)-sizeof(long), m.type, 0)==-1?err("msgrcv"):0;
	printf("message=%s\n", m.text);
	return 0;
}
