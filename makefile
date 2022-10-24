main: main.o epoll.o socket.o
	gcc main.o epoll.o socket.o -o demo
main.o: main.c
epoll.o: epoll.c epoll.h
socket.o: socket.c socket.h

clean:
	rm *.o
	rm demo
