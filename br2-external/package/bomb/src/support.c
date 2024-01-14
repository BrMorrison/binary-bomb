#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

// fgets requires a maximum read size, but the point of this lab is to
// intentionally trigger buffer overflows, so I'm picking a size that should be
// significantly longer than any of the required input.
#define MAX_LINE 2048
#define MAX_PASSWORD 32
#define NUM_PHASES 5

static FILE* InFile = NULL;
static char last_password[MAX_PASSWORD] = "";

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

        // Copy the password that we read. This is used for controlling access
        // to the secret phase.
        strncpy(last_password, buf, MAX_PASSWORD);
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

void phase_defused(int n) {
    static int defuse_count = 0;
    defuse_count += 1;

    // Try and catch any funny business.
    if (defuse_count != n) {
        printf("\nCHEATER!!! Shame on you for trying to mess with the program!\n");
        explode_bomb();
    }

    printf("Phase %d defused!\n", defuse_count);

    if (defuse_count == NUM_PHASES) {
        if (strncmp(last_password, "Gimme secrets!", MAX_PASSWORD) == 0) {
            secret_phase();
            explode_bomb();
        } else {
            printf("Bomb defused! You've completed all of the phases... or have you?\n");
        }
    }
    else if (defuse_count == NUM_PHASES + 1) {
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

void prompt_password(int phase) {
    printf("Phase %d: ", phase);
    fflush(stdout);
}
