#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t;
	char* ct, buf[80];
	struct tm *lt;

	time(&t);
	ct = ctime(&t);
	lt = localtime(&t);
	strftime(buf, 80, "%A:%B:%c:%p:%Z", lt);

	printf("time\t: %ld\n", t);
	printf("ctime\t: %ld\n", ct);
	printf("localtime\n");
	printf("\tyear\t:%d\n", lt->tm_year);
	printf("\tmon\t:%d\n", lt->tm_mon);
	printf("\tmday\t:%d\n", lt->tm_mday);
	printf("\thour\t:%d\n", lt->tm_hour);
	printf("\tmin\t:%d\n", lt->tm_min);
	printf("\tsec\t:%d\n", lt->tm_sec);
	printf("\twday\t:%d\n", lt->tm_wday);
	printf("\tyday\t:%d\n", lt->tm_yday);
	printf("stftime:%s\n", buf);
	return 0;
}
