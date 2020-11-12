#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Home directory is %s\b", getenv("HOME"));
	putenv("HOME=/ ");
	printf("New home directory is %s\n", getenv("HOME"));
	printf("PATH is %s\n", getenv("PATH"));
	printf("USER is %s\n", getenv("USER"));
	printf("MANPATH is %s\n", getenv("MAIL"));
	return 0;
}
