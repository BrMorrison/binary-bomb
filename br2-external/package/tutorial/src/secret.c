#include <stdio.h>
#include <string.h>
#include <signal.h>

#define MAX_STRING 64

const char * secret_string = "I'm a string!";

int secret_func() {
    char buf[MAX_STRING];
    fgets(buf, MAX_STRING, stdin);
    buf[strcspn(buf, "\r\n")] = '\0';
    return (strncmp(buf, "secret password", MAX_STRING) == 0);
}