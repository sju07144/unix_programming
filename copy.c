#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 8192

int main(void)
{
	int fd1, fd2;
	char buf[BUFFSIZE];
	int n;

	fd1 = open("input", O_RDONLY);
	fd2 = open("output", O_RDWR | O_CREAT | O_TRUNC, 0644);

	if((n = read(fd1, buf, BUFFSIZE)) < 0) {
		printf("read error\n");
		exit(1);
	}
	if(write(fd2, buf, n) != n) {
		printf("write error\n");
		exit(1);
	}
	close(fd2);
	close(fd1);
	return 0;
}
