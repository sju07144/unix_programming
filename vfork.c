#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int g = 6;
int main(void)
{
	int var;
	pid_t pid;
	var = 88;
	printf("before vfork\n");
	
	if((pid = vfork()) < 0) {
		perror("vfork error");
		exit(1);
	}

	else if(pid == 0) {
		g++;
		var++;
		_exit(0);
	}

	printf("pid = %d, g = %d, var = %d\n", getpid(), g, var);
	exit(0);
}
