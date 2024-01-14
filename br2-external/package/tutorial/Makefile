# Main makefile for the reverse engineering tutorial
#

COMMON_CFLAGS = -c -Og -fno-stack-protector
PUBLIC_CFLAGS = -g

.PHONY: all clean
all: tutorial tutorial.txt

tutorial.o: src/tutorial.c
	$(CC) $(COMMON_CFLAGS) $(PUBLIC_CFLAGS) -o tutorial.o src/tutorial.c

secret.o: src/secret.c
	$(CC) $(COMMON_CFLAGS) -o secret.o src/secret.c 

tutorial: tutorial.o secret.o
	$(CC) tutorial.o secret.o -o tutorial

# TODO: cat all the individual guides into a monolithic document
tutorial.txt: guides/tutorial.txt
	cat guides/tutorial.txt > tutorial.txt

clean:
	rm -f tutorial tutorial.txt *.o
