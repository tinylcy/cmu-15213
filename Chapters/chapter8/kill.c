#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
	if((pid = fork()) == 0) {
		pause();
		printf("control should never reach here!\n");
		exit(0);
	}

	kill(pid, SIGKILL);
	exit(0);
}
