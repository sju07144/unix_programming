#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myhandler(int signo)
{
	switch (signo) {
		case SIGINT : printf("SIGINT(%d) is caught\n", SIGINT);
			      break;
		case SIGQUIT: printf("SIGQUIT(%d) is caught\n", SIGQUIT);
			      break;
		case SIGTSTP: printf("SIGTSTP(%d) is caught\n", SIGTSTP);
			      break;
		case SIGTERM: printf("SIGTERM(%d) is caught\n", SIGTERM);
			      break;
		case SIGUSR1: printf("SIGUSR1(%d) is caught\n", SIGUSR1);
			      break;
		case SIGALRM: printf("SIGALRM(%d) is caught\n", SIGALRM);
			      break;
		default: printf("other signal\n");
	}
	return;
}

int main(void)
{
	signal(SIGINT, myhandler);
	// signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, myhandler);
	signal(SIGTSTP, myhandler);
	// signal(SIGTERM, SIG_DFL);
	signal(SIGTERM, myhandler);
	signal(SIGUSR1, myhandler);
	for(;;)
		pause();
}
