#include "head_shelly.h"

/**
 * find_executable - checks if file exists and is executable
 * @arg: name of program to search for
 * @paths: array of directories from PATH
 *
 * Return: complete path for program if found, else NULL
 */
char *find_executable(char *arg, char **paths)
{
	int i = 0;
	char *str;

	/* if user passed absolute path to executable, return early */
	if ((access(arg, X_OK) == 0) && (strchr(arg, '/')))
		return (_strdup(arg));

	if (arg == NULL || paths == NULL)
		return (NULL);

	/* increment through each directory name stored in paths array */
	while (paths[i] != NULL)
	{
		/* extra 2 bytes allocated to account for '/' and '\0' */
		str = malloc(strlen(paths[i]) + strlen(arg) + 2);
		if (str == NULL)
		{ 
			perror ("Error: failed to allocate memory");
			exit(EXIT_FAILURE);	
		}
		
		/* combines directory with executable name to form absolute path */
		sprintf(str, "%s/%s", paths[i], arg);
		if (access(str, X_OK) == 0)
		{
			return (str);
		}
		free(str);
		i++;
	}

	return (NULL);
}
