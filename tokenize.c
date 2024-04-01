#include "head_shelly.h"

/**
 * tokenize - tokenizes function
 * @str: string to be tokenized
 *
 * Return: Array
 */

char **tokenize(char *str, char *d)
{
	char *portion = NULL, *new = NULL;
	char **res;
	size_t len = 0;
	int i = 0, ii = 0;
	
	if (!str)
		return (NULL);

/* count the deliminators */
	while (len < strlen(str))
	{
		if (str[len] == d[0])
			i++;
		 len++;
	}
	i++;

/* make room for pointers to the strings */
	res = malloc(sizeof(char *) * (++i));
	if (res == NULL)
		return (NULL);

/* this has to be a duplicate otherwise things break */	
	new = _strdup(str);
	portion = strtok(new, d);
	while (portion)
	{
		res[ii++] = _strdup(portion);
		portion = strtok(NULL, d);
	}
	res[ii] = NULL;
	free(new);

	return (res);
}
