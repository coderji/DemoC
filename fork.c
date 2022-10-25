#include "epoll.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// https://blog.csdn.net/weixin_45003868/article/details/119517712

void sysErr(const char* str) {
	perror(str);
	exit(1);
}

int testForkKill() {
	pid_t pid, q;
	int i;
	int n = 5;

	for (i = 0; i < n; i++) {
		pid = fork();
		if (pid == -1) {
			sysErr("fork error");
		} else if (pid == 0) {
			break;
		}
		if (i == 2) {
			q = pid;
		}
	}

	if (i < 5) {
		while(1) {
			printf("I'm child %d, getpid = %u\n", i, getpid());
			sleep(1);
		}
	} else {
		sleep(1);
		kill(q, SIGKILL); //在父进程中杀死第三个创建的子进程
		while(1);
	}

	return EXIT_SUCCESS;
}
