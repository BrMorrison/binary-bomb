#include <stdio.h>
#include "support.h"

#define BUF_SIZE 32

// Phases 3 and 5 are more interesting when you can see the source code.
void phase_3(void) {
    volatile int bypass_bomb = 0;
    char buf[BUF_SIZE];
    prompt_password(3);
    read_line(buf);

    if (!bypass_bomb) {
        explode_bomb();
    }
}

void phase_5(void) {
    char buf[BUF_SIZE];
    prompt_password(5);
    read_line(buf);
}


int main(int argc, char *argv[]) {

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
    // Add an explosion here just to be safe :)
    explode_bomb();
    phase_defused(5);

    cleanup();
    return 0;
}