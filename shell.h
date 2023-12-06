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
void rd_cmd(char *cmd, size_t size);
void exe_cmd(const char *cmd);
#endif
