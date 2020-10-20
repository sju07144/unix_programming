#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	FILE* fp;
	int c;

	if((fp = fopen(argv[1], "a")) == NULL)
		perror("fopen:");
	fprintf(fp, "Hello World\n");
}
