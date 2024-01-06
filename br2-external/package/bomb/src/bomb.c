#include <stdio.h>
#include <stdlib.h>
#include "support.h"

void prompt_password(void) {
    printf("Password: ");
    fflush(stdout);
}

int main(int argc, char *argv[]) {

    if (argc > 1) {
        init_password_file(argv[1]);
    } else {
        init_password_file(NULL);
    }

    prompt_password();
    phase_1();
    phase_defused();
    printf("Phase 1 defused.\n");

    prompt_password();
    phase_2();
    phase_defused();
    printf("Phase 2 defused.\n");

    prompt_password();
    phase_3();
    phase_defused();
    printf("Phase 3 defused.\n");

    prompt_password();
    phase_4();
    phase_defused();
    printf("Phase 4 defused.\n");

    prompt_password();
    phase_5();
    // Add an explosion here just to be safe :)
    explode_bomb();
    phase_defused();
    printf("Phase 5 defused.\n");

    return 0;
}