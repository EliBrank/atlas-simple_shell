#include "head_shelly.h"

/**
 * free_args - frees strings in array, then array
 * @user_args: pointer to array of strings to free
 */
void free_args(char **user_args)
{
	int i;

	/* frees each string in array, then array itself */
	for (i = 0; user_args[i] != NULL; i++)
		free(user_args[i]);
	free(user_args);
}
