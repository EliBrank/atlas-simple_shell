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

typedef struct env_s
{
    char *var;
    char *value;
    struct env_s *next;
} env_t;

char *builtin_commads[] =
{
    "env"
    "setenv"
    "unsetenv"
    "exit"
};


set
unset
env
char **tokenize(char *buffer);
int fork_exec(char **userArgs);
void free_args(char **userArgs);
int arg_count(char *str);
char *_strdup(char *str);

#endif
