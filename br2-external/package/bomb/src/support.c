#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

// fgets requires a maximum read size, but the point of this lab is to
// intentionally trigger buffer overflows, so I'm picking a size that should be
// significantly longer than any of the required input.
#define MAX_LINE 2048
#define NUM_PHASES 5

static FILE* InFile = NULL;

void init_password_file(const char* password_file) {
    if (password_file == NULL) {
        InFile = stdin;
        return;
    }

    InFile = fopen(password_file, "r");

    if (InFile == NULL) {
        fprintf(stderr, "Error: Could not open password file '%s'\n", password_file);
        exit(1);
    } else {
        printf("Started reading passwords from '%s'\n", password_file);
    }
}

void read_line(char* buf) {
    // TODO: The CMU version skipped whitespace before trying to read a line,
    // which would be a nice quality of life improvement.

    if (fgets(buf, MAX_LINE, InFile) != NULL) {
        // Replace trailing control characters with a terminator.
        buf[strcspn(buf, "\r\n")] = '\0';
        return;
    }

    // We failed to read our input. If we were reading from stdin, we have to
    // give up.
    if (InFile == stdin) {
        fprintf(stderr, "Error: Encountered unexpected EOF on stdin.\n");
        exit(1);
    }

    // If we were using a file, switch to stdin and retry.
    fclose(InFile);
    InFile = stdin;
    read_line(buf);
}

void phase_defused(void) {
    static int defuse_count = 0;
    defuse_count += 1;
    if (defuse_count == NUM_PHASES) {
        // TODO: Add a check for a password if they're at the final phase.
        // TODO: This doesn't print right since the "Phase x defused" gets printed after it
        printf("Bomb defused! You've completed all of the phases... or have you?\n");
    }
}

void explode_bomb(void) {
    printf("\nBOOOOOOM!!!\n");
    printf("The bomb exploded :(\n");

    if (InFile != stdin) {
        fclose(InFile);
    }
    exit(1);
}
