#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define BUFFSIZE 8192

int main(int argc, char* argv[])
{
	int fd, fd2;
	int n;
	char buf[BUFFSIZE];

	if(argc != 3)
	{
		printf("Usage: ./copy2 <Input file> <Output file>\n");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);

	if((n = read(fd, buf, BUFFSIZE)) < 0)
	{
		perror("read error");
		exit(1);
	}

	if(write(fd2, buf, n) != n)
	{
		perror("write error");
		exit(1);
	}

	return 0;
}
