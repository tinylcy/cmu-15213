#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

unsigned int snooze(unsigned int secs) {
	int leftsecs = sleep(secs);
	printf("Slept for %d of %d secs.\n", secs - leftsecs, secs);
	return secs - leftsecs;
}

void sigint_handler(int sig) {
	
}

int main(void) {
	if(signal(SIGINT, sigint_handler) == SIG_ERR) {
		perror("signal error.");
	}

	snooze(10);
}
