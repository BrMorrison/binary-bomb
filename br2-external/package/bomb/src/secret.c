#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

#define NUM_PHASES 3
#define BUF_SIZE 32

void phase_defused(void) {
    static int defuse_count = 0;
    defuse_count += 1;
    if (defuse_count == NUM_PHASES) {
        // TODO: Add a check for a password if they're at the final phase.
        printf("Bomb defused! You've completed all of the phases... or have you?\n");
    }
}

void explode_bomb(void) {
    printf("\nBOOOOOOM!!!\n");
    printf("The bomb exploded :(\n");
    exit(1);
}

void phase_1(void) {
    char buf[BUF_SIZE];
    gets(buf);

    int strings_different = strcmp(buf, "evil password");
    if (strings_different) {
        explode_bomb();
    }
}

void phase_2(void) {
    char buf[BUF_SIZE];
    gets(buf);

    // Make sure the input it 9 characters
    if (strlen(buf) != 9) {
        explode_bomb();
    }

    // Make sure buf[3] > buf[7] && (buf[3] - buf[2]) == 6
    if ((buf[3] > buf[7]) && (buf[3] - buf[2] != 10)) {
        explode_bomb();
    }
}

void phase_3(void) {
    // This is where we start messing with the stack. Here we need to set
    // the flag by overflowing the buffer.
    volatile int bypass_bomb = 0;
    char buf[BUF_SIZE];
    gets(buf);

    if (!bypass_bomb) {
        explode_bomb();
    }
}

void phase_4(void) {
    // Now they'll have to overwrite the buffer here while having buf also be
    // a normal string that matches a second password
    char second_password[5] = "bomb";
    char buf[BUF_SIZE];
    gets(buf);

    // Make sure the first password is good.
    int strings_different = strcmp(buf, "there's no escape :)");
    if (strings_different) {
        explode_bomb();
    }

    // Check the second password too.
    strings_different = strcmp(second_password, "safe");
    if (strings_different) {
        explode_bomb();
    }
}

void phase_5(void) {
    // This is where they'll have to overwrite the return pointer in order to
    // avoid a forced explosion.
    char buf[BUF_SIZE];
    gets(buf);
}

void secret_phase(void) {
    // Have them overwrite the stack to perform RCE in order to jump to a
    // specific function
    char buf[BUF_SIZE];
    gets(buf);

    // Not sure what code I can force them run though. Maybe calling a function
    // with certain parameters?
    // Maybe a function that requires some kind of decryption key as a parameter
}