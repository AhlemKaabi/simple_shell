#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <linux/limits.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd, w;
	
	char *input = "add me to history";
	fd = open("history.txt", O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, )
	return (0);
}