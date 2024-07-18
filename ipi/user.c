#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "mymod.h"

int main(int argc, char *argv[])
{
	int ret = 0;

	if (argc < 4) {
		fprintf(stderr, "USAGE: %s <path> <op> <arg>\n", argv[0]);
		ret = 1;
		goto out;
	}

	const char *path = argv[1];
	const unsigned long op = atol(argv[2]);
	const unsigned long arg = atol(argv[3]);
	printf("args - path:%s, op:%c, arg:%lu\n", path, op, arg);

	const int fd = open(path, O_RDWR);
	if (fd < 0) {
		perror("open");
		ret = errno;
		goto out;
	}

	ret = ioctl(fd, MYMOD_A, arg);
	if (ret < 0) {
		perror("ioctl");
		goto cleanup;
	}

cleanup:
	close(fd);
out:
	return ret;
}
