main: main.o epoll.o
	gcc main.o epoll.o -o demo
main.o: main.c
epoll.o: epoll.c epoll.h

clean:
	rm *.o
	rm demo
