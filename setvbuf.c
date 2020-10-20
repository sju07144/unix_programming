#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i;
//	setvbuf(stdout, NULL, _IOFBF, 3);
//	setvbuf(stdout, NULL, _IOLBF, 3);
	setvbuf(stdout, NULL, _IONBF, 3);
	for (i = 'A'; i <= 'J'; i++) {
		fprintf(stdout, "%c", i);
		if(i == 'F') fprintf(stdout, "\n");
		sleep(1);
	}
}
