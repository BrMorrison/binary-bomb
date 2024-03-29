#include <stdio.h>
#include <string.h>
#include <signal.h>

#define MAX_STRING 64

extern const char * secret_string;
int bar = 0;

int secret_func();

void foo(int n) {
    // Uh-oh, this function will take a long time to step through manually.
    // Run to the end with `finish`
    for (int i = 0; i < n; ++i) {
        ++bar; // Increment the var so we don't get optimized out :(
    }
}

int examining_data() {
    char buf[MAX_STRING];
    fgets(buf, MAX_STRING, stdin);
    // We have to replace the newline with a terminator because fgets is
    // dumb.
    buf[strcspn(buf, "\r\n")] = '\0';

    // The function will return true when the input matches `secret_string`
    int strings_equal = strncmp(buf, secret_string, MAX_STRING) == 0;
    return strings_equal;
}

int main(int argc, char *argv[]) {

    // Welcome to the bomb defusal tutorial!
    volatile int val = 0;

    // Try stepping through this code with `step` or `next`
    val = 256;
    val = val * val;

    // Try stepping into foo() with `step`
    foo(val);
    // Now try stepping over it.
    foo(val);

    // printf is a library function. We'll almost always want to step over it
    // with [n]ext.
    printf("GDB is fun!\n");

    // For to get past the next part you'll need to read the "Examining Data"
    // section of the tutorial.

    // `examining_data()` will prompt you for a secret string and you'll have
    // to use gdb to figure out the correct value and get past this loop.
    while (!examining_data()) {
        ; // Do nothing until the function returns true.
    }

    // We don't have the source code for this function! In order to debug it,
    // we'll have to work with the disassembly. Read the "Working with Assembly"
    // section of the tutorial to learn more.
    while (!secret_func()) {
        ; // Do nothing until the function returns true.
    }

    return 0;
}
