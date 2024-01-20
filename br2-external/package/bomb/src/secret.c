#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

#define BUF_SIZE 32

void phase_1(void) {
    char buf[BUF_SIZE];
    prompt_password(1);
    read_line(buf);

    int strings_different = strcmp(buf, "evil password");
    if (strings_different) {
        explode_bomb();
    }
}

void phase_2(void) {
    char buf[BUF_SIZE];
    prompt_password(2);
    read_line(buf);

    // Make sure the input it 9 characters
    if (strlen(buf) != 9) {
        explode_bomb();
    }

    // Make sure buf[3] > buf[7] && (buf[3] - buf[2]) == 6
    if ((buf[3] > buf[7]) || (buf[3] - buf[2] != 10)) {
        explode_bomb();
    }
}

void secret_phase(void) {
    // Have them overwrite the stack to perform ACE in order to jump to a
    // specific function
    char buf[BUF_SIZE];
    prompt_password(6);
    read_line(buf);
}
