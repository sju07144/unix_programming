#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	if((fd = creat("testfile", 0744)) < 0)
		printf("create error\n");
}
