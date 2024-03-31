#include "head_shelly.h"

/**
 * env_get - gets environment variable value matching input string
 * @env_list: list of environment variables to look through
 * @var: name of environment variable to check for
 *
 * Return: value of environment variable if found, else NULL
 */
char *env_get(env_t **environ, char *var)
{
	char *delim = "=";
	unsigned int i;
	int len;
	char *env_value;

	/* added 1 to length of var string accounts for '=' sign */
	len = strlen(var) + 1;
	
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, len) == 0)
		{
			break;
		}
	}

	if (environ[i] == NULL)
		return (NULL);

	/* strtok is run once to strip off the variable name and '=' */
	strtok(environ[i], delim);

	/* now output of strtok will be environment variable's value */
	env_value = _strdup(strtok(NULL, delim));
	if (env_value == NULL)
	{
		perror("Error: value not found");
		exit(EXIT_FAILURE);
	}

	return (env_value);
}
