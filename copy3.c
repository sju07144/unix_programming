#include <stdio.h>
#include <errno.h>

int main(void)
{
	FILE *fp1, *fp2;
	char str[80];
	if((fp1 = fopen("input", "r")) == NULL)
		perror("fopen:");

	if((fp2 = fopen("output", "w")) == NULL)
		perror("fopen:");
	
	while((fgets(str, 80, fp1)) != NULL)
		fputs(str, fp2);
}
	
