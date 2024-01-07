#ifndef SUPPORT_H
#define SUPPORT_H

void explode_bomb(void);
void phase_defused(void);
void init_password_file(const char *);
void read_line(char *);
void prompt_password(void);
void cleanup(void);

void phase_1(void);
void phase_2(void);
void phase_3(void);
void phase_4(void);
void phase_5(void);

#endif