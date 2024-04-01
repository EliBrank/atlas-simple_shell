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

int _isspace(char *str);
char *_strdup(char *str);
int arg_count(char *str);
char *delim_to_space(char *str, char *delim);
char *env_get(char **environ, char *var);
char *find_executable(char *arg, char **paths);
int fork_exec(char *exec_name, char **user_args, char **env, int *);
void free_string_array(char **str_array);
void print_env(char **env);
char **tokenize(char *str, char *delim);

#endif
