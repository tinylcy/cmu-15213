#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define N 2

int main(void) {
	int i, status;
	pid_t retpid;
	pid_t pid[N];

	for(i = 0; i < N; i++) {
		retpid = fork();
		if(retpid == 0) {
			exit(100 + i);
		} else {
			pid[i] = retpid;
		}
	}

	i = 0;
	while((retpid = waitpid(pid[i++], &status, 0)) > 0) {
		if(WIFEXITED(status)) {
			printf("child %d terminated normally with exit status %d\n", retpid, WEXITSTATUS(status));
		} else {
			printf("chaild %d terminated abnormally\n", retpid);
		}
	}

	if(errno != ECHILD) {
		fprintf(stderr, "waitpid error");
	}

	exit(0);
}
