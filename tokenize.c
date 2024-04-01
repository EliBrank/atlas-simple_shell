#include "head_shelly.h"

/**
 * tokenize - tokenizes function
 * @str: string to be tokenized
 *
 * Return: Array
 */

char **tokenize(char *str, char *delim)
{
	char *portion = NULL, *new_str = NULL;
	char **array;
	size_t len = 0;
	int count = 0, i = 0;
	
	if (!str)
		return (NULL);

	/* count the delimiters */
	while (len < strlen(str))
	{
		if (str[len] == delim[0])
			count++;
		 len++;
	}
	count++;

	/* make room for pointers to the strings */
	array = malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);

	/* this has to be a duplicate otherwise things break */	
	new_str = _strdup(str);
	portion = strtok(new_str, delim);
	while (portion)
	{
		array[i] = _strdup(portion);
		portion = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	free(new_str);

	return (array);
}
