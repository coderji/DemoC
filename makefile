main: main.o epoll.o fork.o socket.o
	gcc main.o epoll.o fork.o socket.o -o demo
main.o: main.c
epoll.o: epoll.c epoll.h
fork.o: fork.c fork.h
socket.o: socket.c socket.h

clean:
	rm *.o
	rm demo
