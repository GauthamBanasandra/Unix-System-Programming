#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct mymsg
{
   long type;       
   char msg[20];     
};
int main()
{
	int id;
	struct mymsg m;
	id =  msgget(ftok("/home/kumar/pesit-2016/USP", 'A'), IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("msgget"); exit(1);
	}
	printf("enter a type : ");
	scanf("%ld", &m.type);
	if(msgrcv(id, (void*)&m, sizeof(m) - sizeof(long), m.type, 0 ) < 0)
	{
		perror("msgsend : "); exit(2);
	}
	printf("msg recd\n");
	printf("msg : %s\n", m.msg);

}
