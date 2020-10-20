#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define MAXBUF 1024

int main(int argc, char* argv[])
{
	FILE* source, *dest;
	char buf[MAXBUF];
	int count;
	
	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if((source = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s: ", argv[1]);
		perror("");
		exit(1);
	}

	if((dest = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Can't open %s: ", argv[2]);
		perror("");
		exit(1);
	}

	while((count = fread(buf, 1, MAXBUF, source)))
	{
		if(fwrite(buf, 1, count, dest) == 0)
		{
			perror("fwrite");
			exit(1);
		}
	}

	if(ferror(source))
	{
		perror("fread");
		exit(1);
	}
	fclose(source);
	fclose(dest);
}
