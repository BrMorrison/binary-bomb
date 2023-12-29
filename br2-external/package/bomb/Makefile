# Main makefile for the binary bomb
#

# TODO: We might want to do this in some kind of build directory so that it's
# easier to have git ignore all of the outputs? Though I guess that doesn't
# really matter if the actual build is happening in buildroot's tree.
all: bomb guide.txt

# TODO: Actually build the bomb binary
bomb:
	touch bomb

# TODO: cat all the individual guides into a monolithic document
guide.txt:
	touch guide.txt

clean:
	rm -f bomb guide.txt
