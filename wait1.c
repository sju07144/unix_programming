#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;
	if((pid = fork()) < 0)
	{
		printf("I am a child\n");
		exit(123);
	}
	/*parent process*/
	pid = wait(&status);
	printf("parent: child(pid = %d) is terminated with status (%d)\n", pid, WEXITSTATUS(status));
}
