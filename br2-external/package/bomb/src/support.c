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

void cleanup(void) {
    if (InFile != stdin) {
        fclose(InFile);
    }
}

void init_password_file(const char* password_file) {
    if (password_file == NULL) {
        InFile = stdin;
        return;
    }

    InFile = fopen(password_file, "r");

    if (InFile == NULL) {
        fprintf(stderr, "Error: Could not open password file '%s'\n", password_file);
        exit(EXIT_FAILURE);
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
        exit(EXIT_FAILURE);
    }

    // If we were using a file, switch to stdin and retry.
    fclose(InFile);
    InFile = stdin;
    read_line(buf);
}

void phase_defused(void) {
    static int defuse_count = 0;
    defuse_count += 1;
    printf("Phase %d defused!\n", defuse_count);
    if (defuse_count == NUM_PHASES + 1) {
        printf("\nSUCCESS!!!\n");
        printf("You completed the secret phase! The bomb is fully defused!\n");
        cleanup();
        exit(EXIT_SUCCESS);
    }
}

void explode_bomb(void) {
    printf("\nBOOOOOOM!!!\n");
    printf("The bomb exploded :(\n");

    cleanup();
    exit(EXIT_FAILURE);
}

void prompt_password(void) {
    printf("Password: ");
    fflush(stdout);
}
