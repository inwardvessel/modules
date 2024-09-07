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

#define QUIT 0

int main(int argc, char *argv[])
{
	int ret = 0;

	if (argc < 2) {
		fprintf(stderr, "USAGE: %s <path/to/chardev>\n", argv[0]);
		ret = 1;
		goto out;
	}

	const char *path = argv[1];
	const int fd = open(path, O_RDWR);
	if (fd < 0) {
		perror("open");
		ret = errno;
		goto out;
	}

	const int choices[] = {
		QUIT,
		MYMOD_MUTEX_LOCK,
		MYMOD_MUTEX_UNLOCK,
		MYMOD_SPIN_LOCK,
		MYMOD_SPIN_UNLOCK,
		MYMOD_CALLBACK_GOOD,
		MYMOD_CALLBACK_BAD_BLOCKING,
		MYMOD_CALLBACK_BAD_NONBLOCKING,
	};

	const char prompt[] = {
		"0: quit\n"
		"1: mutex lock\n"
		"2: mutex unlock\n"
		"3: spin lock\n"
		"4: spin unlock\n"
		"5: callback good\n"
		"6: callback blocking\n"
		"7: callback spinning\n"
		"choice? "
	};

	char input[64] = {};
	for (;;) {
		printf("%s", prompt);
		fflush(stdout);

		ssize_t bytes = read(STDIN_FILENO, input, sizeof(input));
		if (bytes < 0) {
			perror("read");
			ret = bytes;
			break;
		}

		const unsigned int choice = atoi(input);
		if (choice > (sizeof(choices) / sizeof(choices[0]))) {
			fprintf(stderr, "invalid choice: %u\n", choice);
			ret = 1;
			break;
		} else if (choice == 0) {
			puts("quitting");
			break;
		}

		const int cmd = choices[choice];

		ret = ioctl(fd, cmd, NULL);
		if (ret < 0) {
			perror("ioctl");
			goto cleanup;
		}
	}

cleanup:
	close(fd);
out:
	return ret;
}
