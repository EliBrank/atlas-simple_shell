#include "head_shelly.h"

/**
 * find_executable - checks if file exists and is executable
 * @arg: name of program to search for
 * @paths: array of directories from PATH
 *
 * Return: complete path for program if found, else NULL
 */
char* find_executable(char *arg, char **paths)
{
	int i = 0;
	char *str;

	if (arg == NULL || paths == NULL)
		return (NULL);

	if (access(arg, X_OK) == 0)
		return (strdup(arg));

	while (paths[i] != NULL)
	{
		str = malloc(strlen(paths[i]) + strlen(arg) + 2);
		if (str == NULL)
		{ 
			perror ("Error: failed to allocate memory");
			exit(EXIT_FAILURE);	
		}
		
		sprintf(str, "%s/%s", paths[i], arg);
		/* ARA: changed this to == 0 because access returns 0 on success */
		if (access(str, X_OK) == 0)
		{
			return (str);
		}
		free(str);
		i++;
	}

	return (NULL);
}