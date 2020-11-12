#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	printf("Hello, my pid is %d\n", getpid());
	if((pid = fork()) == 0) {
		printf("child : pid = %d, ppid = %d\n", getpid(), getppid());
	}
	else {
		printf("parent : I created child with pid = %d\n", pid);
	}

	printf("Bye my pid is %d\n", getpid());
	sleep(20);
	return 0;
}
