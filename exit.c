#include <stdio.h>
#include <stdlib.h>

void exit1(void)
{
	puts("exit1");
}

void exit2(void)
{
	puts("exit2");
}

int main(void)
{
	atexit(exit1);
	atexit(exit2);
	exit(1);
	_exit(1);
}
