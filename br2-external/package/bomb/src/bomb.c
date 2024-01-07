#include <stdio.h>
#include "support.h"

int main(int argc, char *argv[]) {

    init_password_file(argc > 1 ? argv[1] : NULL);

    prompt_password();
    phase_1();
    phase_defused();

    prompt_password();
    phase_2();
    phase_defused();

    prompt_password();
    phase_3();
    phase_defused();

    prompt_password();
    phase_4();
    phase_defused();

    prompt_password();
    phase_5();
    // Add an explosion here just to be safe :)
    explode_bomb();
    phase_defused();

    printf("Bomb defused! You've completed all of the phases... or have you?\n");

    cleanup();
    return 0;
}