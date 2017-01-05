#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void sigint_handler(int sig) {
	printf("Caught SIGINT!\n");
//	exit(0);
}

int main(void) {
	if(signal(SIGINT, sigint_handler) == SIG_ERR) {
		perror("signal error.");
	}

	pause();
	
	printf("会执行这句话吗?\n");
	return 0;
}
