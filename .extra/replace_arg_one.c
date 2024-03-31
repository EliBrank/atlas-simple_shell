#include "head_shelly.h"

/**
 * replace_arg_one - swaps out first user arg for amended version
 * @original_arg: the original value for the first user arg
 * @new_arg: the amended user arg (may be same as original)
 */
void replace_arg_one(char **original_arg, const char *new_arg)
{
	char *tmp;

	/* change first arg (program name) to include absolute path */
	/* only reallocates memory for this arg in array if changed */
	if (strlen(new_arg) > strlen(*original_arg))
	{
		/* reallocate memory for the first string */
		tmp = realloc(*original_arg, (strlen(new_arg) + 1) * sizeof(char));
		if (tmp == NULL)
		{
			perror("Error: failed memory allocation");
			exit(EXIT_FAILURE);
		}
		*original_arg = tmp;
	}
	strcpy(*original_arg, new_arg);
}
