#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

unsigned int snooze(unsigned int secs);

int main(void) {
	
	snooze(5);
	exit(0);
}

unsigned int snooze(unsigned int secs) {
	unsigned int leftsecs = sleep(secs);
	printf("Slept %d for %d secs.\n", (secs - leftsecs), secs);
	return leftsecs;
}
