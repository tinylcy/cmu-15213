#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
	int i;

	printf("Command line arguments:\n");
	for(i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	printf("Environment variables:\n");
	for(i = 0; envp[i] != NULL; i++) {
		printf("envp[%d]: %s\n", i, envp[i]);
	}

	exit(0);
}
