#include "head_shelly.h"

/**
 * env_get - gets environment variable value matching input string
 * @env_list: list of environment variables to look through
 * @var: name of environment variable to check for
 *
 * Return: value of environment variable if found, else NULL
 */
char *env_get(env_t *env_list, char *var)
{
    env_t *tmp = *env_list;
	unsigned int i;

	i = 0;
	while (tmp != NULL)
	{
		if (strcmp(tmp->var, var) == 0)
			return (tmp->value);
		i++;
		tmp = tmp->next;
	}

	return (NULL);
}
