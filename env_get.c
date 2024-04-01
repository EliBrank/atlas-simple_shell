#include "head_shelly.h"

/**
 * env_get - gets environment variable value matching input string
 * @env_list: list of environment variables to look through
 * @var: name of environment variable to check for
 *
 * Return: value of environment variable if found, else NULL
 */

char *env_get(char **environ, char *var)
{
	unsigned int i;
	int len;

	len = strlen(var);
	
	/* for each key/value pair in array, check if the var name matches */
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, len) == 0)
		{
			break;
		}
	}

	/* if key/value pair in array not found, environ[i] will reach NULL */
	if (environ[i] == NULL)
		return (NULL);

	/* returns the value after '=' if '=' exists in right spot */
	if (*(environ[i] + len) == '=')
		return (environ[i] + len + 1);

	return (NULL);
}
