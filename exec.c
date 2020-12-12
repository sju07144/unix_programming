#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;

	if((pid = fork()) < 0)
		printf("fork error");
	else if(pid == 0) {
		printf("Child : %d\n", getpid());
		if(execl("/usr/bin/ps", "ps", "-f", 0) < 0)
			printf("execl error");
	}

	printf("Parent : %d\n", getpid());
	if(waitpid(pid, NULL, 0) < 0)
		printf("waitpid error");
	exit(0);
}
