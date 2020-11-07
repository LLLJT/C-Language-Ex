CC=gcc
CFLAGS= -lm -Wall -g
hello: a.c
	$(CC) $(CFLAGS) a.c -o hello
clean:
	rm hello
