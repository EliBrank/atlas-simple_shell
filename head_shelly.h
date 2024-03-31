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
int fork_exec(char *exec_name, char **user_args, char **env);
void free_string_array(char **str_array);
int arg_count(char *str);
char *_strdup(char *str);
void replace_arg_one(char **original_arg, const char *new_arg);

#endif
