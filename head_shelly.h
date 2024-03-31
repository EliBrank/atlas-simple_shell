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

char **tokenize(char *buffer);
int fork_exec(char **user_args);
void free_string_array(char **str_array);
int arg_count(char *str);
char *_strdup(char *str);
void replace_arg_one(char **original_arg, const char *new_arg);

#endif
