# Main makefile for the binary bomb
#

#COMMON_CFLAGS = -c -Og -fstack-protector-explicit
COMMON_CFLAGS = -c -Og -fno-stack-protector
PUBLIC_CFLAGS = -g

.PHONY: all clean
# TODO: We might want to do this in some kind of build directory so that it's
# easier to have git ignore all of the outputs? Though I guess that doesn't
# really matter if the actual build is happening in buildroot's tree.
all: bomb guide.txt

bomb.o: src/bomb.c
	$(CC) $(COMMON_CFLAGS) $(PUBLIC_CFLAGS) -o bomb.o src/bomb.c

secret.o: src/secret.c
	$(CC) $(COMMON_CFLAGS) -o secret.o src/secret.c 

# TODO: Actually build the bomb binary
bomb: bomb.o secret.o
	$(CC) bomb.o secret.o -o bomb

# TODO: cat all the individual guides into a monolithic document
guide.txt:
	touch guide.txt

clean:
	rm -f bomb guide.txt *.o
