#include <stdio.h>
#include <string.h>
#include "support.h"

#define BUF_SIZE 32

// Phases 3-5 are more interesting when you can see the source code.
void phase_3(void) {
    volatile int bypass_bomb = 0;
    char buf[BUF_SIZE];
    prompt_password(3);
    read_line(buf);

    if (!bypass_bomb) {
        explode_bomb();
    }
}

void phase_4(void) {
    // Now there are two passwords that have to match!
    char second_password[5] = "bomb";
    char buf[BUF_SIZE];
    prompt_password(4);
    read_line(buf);

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
    // We don't need to do much here. We'll explode the bomb when we return.
    char buf[BUF_SIZE];
    prompt_password(5);
    read_line(buf);
}


int main(int argc, char *argv[]) {
    // This opens and starts reading from the password file if the user
    // provided one. You can just step over it.
    init_password_file(argc > 1 ? argv[1] : NULL);

    phase_1();
    phase_defused(1);

    phase_2();
    phase_defused(2);

    phase_3();
    phase_defused(3);

    phase_4();
    phase_defused(4);

    phase_5();
    // Have an explosion here, just to be safe :)
    explode_bomb();
    phase_defused(5);

    cleanup();
    return 0;
}
