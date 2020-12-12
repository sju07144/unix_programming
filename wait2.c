#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;
	if((pid = fork()) == 0) {
		printf("I am a child with pid = %d\n", getpid());
		sleep(30);
		printf("child terminates\n");
		exit(0);
	}
	else {
		while(1) {
			waitpid(pid, &status, WUNTRACED);
			if(WIFSTOPPED(status)) {
				printf("child stopped, signal(%d)\n", WSTOPSIG(status));
				continue;
			}
			else if(WIFEXITED(status))
				printf("normal termination with status(%d)\n", WEXITSTATUS(status));
			else if(WIFSIGNALED(status))
				printf("abnormal termination, signal(%d)\n", WTERMSIG(status));
			exit(0);
		}
	}
}
