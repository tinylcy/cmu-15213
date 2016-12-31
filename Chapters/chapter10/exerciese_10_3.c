#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd;
	char c;

	fd = open("foobar.txt", O_RDONLY, 0);
	if(fork() == 0) {
		read(fd, &c, 1);
		exit(0);
	}

	wait(NULL);
	read(fd, &c, 1);
	printf("c = %c\n", c);

	return 0;
}
