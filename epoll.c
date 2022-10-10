#include "epoll.h"
#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>

// https://blog.csdn.net/tjcwt2011/article/details/125169005

int testEpoll() {
	int epfd, nfds;
	struct epoll_event ev, events[5];
	epfd = epoll_create(1);
	ev.data.fd = STDIN_FILENO;
	ev.events = EPOLLIN | EPOLLET;
	epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev);
	for (;;) {
		nfds = epoll_wait(epfd, events, 5, 2000);
		for (int i = 0; i < nfds; i++) {
			if (events[i].data.fd == STDIN_FILENO) {
				printf("welcome to epoll's world!\n");
			}
		}
		printf("for loop\n");
	}
	return 0;
}
