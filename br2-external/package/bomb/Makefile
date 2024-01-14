# Main makefile for the binary bomb
#

#COMMON_CFLAGS = -c -Og -fstack-protector-explicit
COMMON_CFLAGS = -c -Og -fno-stack-protector
PUBLIC_CFLAGS = -g

.PHONY: all clean
all: bomb guide.txt

bomb.o: src/bomb.c
	$(CC) $(COMMON_CFLAGS) $(PUBLIC_CFLAGS) -o bomb.o src/bomb.c

secret.o: src/secret.c
	$(CC) $(COMMON_CFLAGS) -o secret.o src/secret.c 

support.o: src/support.c
	$(CC) $(COMMON_CFLAGS) -o support.o src/support.c 

bomb: bomb.o secret.o support.o
	$(CC) -z execstack -o bomb bomb.o secret.o support.o

guide.txt: guides/readme.txt guides/phase-1.txt guides/phase-2.txt guides/phase-3.txt guides/phase-4.txt guides/phase-5.txt guides/secret-phase.txt
	cat guides/readme.txt guides/phase-1.txt guides/phase-2.txt guides/phase-3.txt guides/phase-4.txt guides/phase-5.txt guides/secret-phase.txt > guide.txt

clean:
	rm -f bomb guide.txt *.o
