#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	int i;
	struct stat buf;
	char* ptr;
	for(i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		if(stat(argv[i], &buf) < 0) {
			perror("lstat error");
			continue;
		}
		if	(S_ISREG(buf.st_mode))  ptr = "regular";
		else if	(S_ISDIR(buf.st_mode))  ptr = "directory";
		else if	(S_ISCHR(buf.st_mode))  ptr = "character special";
		else if	(S_ISBLK(buf.st_mode))  ptr = "block special";
		else if	(S_ISFIFO(buf.st_mode)) ptr = "fifo";
		else				ptr = "** unknown mode **";
		printf("%s\n", ptr);
	}
	printf("inode # : %d\n", buf.st_ino);
	printf("size : %d\n", buf.st_size);
	printf("blksize : %d\n", buf.st_blksize);
	printf("blocks : %d\n", buf.st_blocks);
	printf("atime : %d\n", buf.st_atime);
	printf("atime : %s\n", ctime(&buf.st_atime));
	exit(0);
}
