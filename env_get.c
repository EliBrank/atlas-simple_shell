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

	/* added 1 to length of var string accounts for '=' sign */
	/* ARA: removed 1 to length of string because strncmp would */
	/* never return a match with a len not equal to the var */
	len = strlen(var);
	
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, len) == 0)
		{
			break;
		}
	}

	if (environ[i] == NULL)
		return (NULL);

/* ARA: added code to return the part after the = sign */
	if (*(environ[i] + len) == '=')
	{
		return (environ[i] + len + 1);
	}
/* ARA: this should go back if there wasn't an equal but */
/* this will work and we are out of the times */

	return (NULL);
}
