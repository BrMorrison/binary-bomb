# Main makefile for the binary bomb
#

#COMMON_CFLAGS = -c -Og -fstack-protector-explicit
COMMON_CFLAGS = -c -Og -fno-stack-protector
PUBLIC_CFLAGS = -g

.PHONY: all clean
all: bomb guide.html

bomb.o: src/bomb.c
	$(CC) $(COMMON_CFLAGS) $(PUBLIC_CFLAGS) -o bomb.o src/bomb.c

secret.o: src/secret.c
	$(CC) $(COMMON_CFLAGS) -o secret.o src/secret.c 

support.o: src/support.c
	$(CC) $(COMMON_CFLAGS) -o support.o src/support.c 

bomb: bomb.o secret.o support.o
	$(CC) -z execstack -o bomb bomb.o secret.o support.o

guide.adoc: guides/readme.adoc guides/phase-1.adoc guides/phase-2.adoc guides/phase-3.adoc guides/phase-4.adoc guides/phase-5.adoc guides/secret-phase.adoc
	cat guides/readme.adoc guides/phase-1.adoc guides/phase-2.adoc guides/phase-3.adoc guides/phase-4.adoc guides/phase-5.adoc guides/secret-phase.adoc > guide.adoc

guide.html: guide.adoc
	asciidoc -o guide.html guide.adoc

clean:
	rm -f bomb guide.html guide.adoc *.o
