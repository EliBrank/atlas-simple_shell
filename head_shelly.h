#ifndef _SHELLY_
#define _SHELLY_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

char **tokenize(char *buffer);
int fork_exec(char **userArgs);
void free_args(char **userArgs);
int arg_count(char *str);

#endif