#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
void n_print(const char *msg);
void t_prmpt(void);
void rd_cmd( char **cmd);
void exe_cmd(const char *cmd, char *envrn[]);
int main(void);
char *find_command(const char *cmd);
#endif/*SHELL_H*/
