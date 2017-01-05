#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

#define MAXBUF 1024

void handler2(int sig) {
	int olderrno = errno;
	while(waitpid(-1, NULL, 0) > 0) {
		printf("handler reaped child\n");
	}
	sleep(1);
	errno = olderrno;
}

int main(void) {
	int i, n;
	char buf[MAXBUF];

	if(signal(SIGCHLD, handler2) == SIG_ERR) {
		perror("signal error");
	}

	for(i = 0; i < 3; i++) {
		if(fork() == 0) {
			printf("Hello from child %d\n", (int)getpid());
			exit(0);
		}
	}

	if((n = read(0, buf, sizeof(buf))) < 0) {
		perror("read");
	}

	printf("Parent processing input\n");
	while(1) {
		;
	}

	exit(0);
}
