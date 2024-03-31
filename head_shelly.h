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

typedef struct func_s
{
    char *builtIn;
    int (*function)(char *);
} func_t;

char **tokenize(char *buffer, char *delim);
int fork_exec(char **userArgs);
void free_args(char **userArgs);
int arg_count(char *str);
char *_strdup(char *str);
char* find_executable(char *arg, char **paths);
char *delim_to_space(char *str, char *delim);
env_t *env_convert_to_node(char *keyValuePair);
int env_delete_node(env_t **head, char *env_var);
char *env_get(env_t *env_list, char *var);
env_t *prepend_env_node(env_t **head, char *var);
env_t *env_setup(char **environ);

#endif
