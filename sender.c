#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define DEFINED_KEY 0x10101011

int main(int argc, char **argv)
{
	int msg_qid;
	struct {
		long mtype;
		char content[256];
	} msg;

	fprintf(stdout, "=========SENDER==========\n");
	if((msg_qid = msgget(DEFINED_KEY, IPC_CREAT | 0666)) < 0) {
		perror("msgget: "); exit(-1);
	}

	msg.mtype = 1;
	while(1) {
		memset(msg.content, 0x0, 256);
		gets(msg.content);
		if(msgsnd(msg_qid, &msg, sizeof(msg.content), 0) < 0) {
			perror("msgsnd: "); exit(-1);
		}
	}
}
