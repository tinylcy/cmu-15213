#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAXARGS 128
#define MAXLINE 1024

void eval(char *cmdline);
int parseline(char *buf, char **argv);
int buildin_command(char **argv);

int main(void) {
	char cmdline[MAXARGS];

	while(1) {
		printf("> ");
		fgets(cmdline, MAXLINE, stdin);
		if(feof(stdin)) {
			exit(0);
		}

		eval(cmdline);
	}
}

void eval(char *cmdline) {
	char *argv[MAXARGS];
	char buf[MAXLINE];
	int bg;
	pid_t pid;

	strcpy(buf, cmdline);
	bg = parseline(buf, argv);
	if(argv[0] == NULL) {
		return;
	}

	if(!buildin_command(argv)) {
		if((pid = fork()) == 0) {
			if(execve(argv[0], argv, NULL) < 0) {
				printf("%s: Command not found.\n", argv[0]);
				exit(0);
			}
		}

		if(!bg) {
			int status;
			if(waitpid(pid, &status, 0) < 0) {
				fprintf(stderr, "waitpid error");
			}
		} else {
			printf("%d %s\n", pid, cmdline);
		}
	}

	return;
}

int buildin_command(char **argv) {
	if(!strcmp(argv[0], "quit")) {
		exit(0);
	}
	if(!strcmp(argv[0], "&")) {
		return 1;
	}
	return 0;
}

int parseline(char *buf, char **argv) {
	char *delim;
	int argc;
	int bg;

	buf[strlen(buf) - 1] = ' ';
	while(*buf && (*buf == ' ')) {
		buf++;
	}

	argc = 0;
	while((delim = strchr(buf, ' '))) {
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while(*buf && (*buf == ' ')) {
			buf++;
		}
	}
	argv[argc] = NULL;
	
	if(argc == 0) {
		return 1;
	}

	if(*(argv[argc - 1]) == '&') {
		bg = 1;
		argv[--argc] = NULL;
	}

	return bg;
}
