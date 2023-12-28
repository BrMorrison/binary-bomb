#include <stdio.h>
#include <stdlib.h>
#include "support.h"

int main(int argc, char *argv[]) {
    printf("Password: ");
    phase_1();
    phase_defused();
    printf("Phase 1 diffused.\n");

    printf("Password: ");
    phase_2();
    phase_defused();
    printf("Phase 2 diffused.\n");

    printf("Password: ");
    phase_3();
    phase_defused();
    printf("Phase 3 diffused.\n");

    printf("Password: ");
    phase_4();
    phase_defused();
    printf("Phase 4 diffused.\n");

    printf("Password: ");
    phase_5();
    // Add an explosion here just to be safe :)
    explode_bomb();
    phase_defused();
    printf("Phase 5 diffused.\n");

    return 0;
}