#include "head_shelly.h"

/**
 * _strdup - duplicates string
 * @str: string to be duplicated
 *
 * Return: pointer to duplicated string, NULL if failure
 */
char *_strdup(char *str)
{
	int len;
	char *new;

	if (str == NULL)
		return (NULL);

	len = strlen(str);

	new = malloc(len * sizeof(char) + 1);
	if (new == NULL)
		return (NULL);

	new = strncpy(new, str, len);

	return (new);
}
