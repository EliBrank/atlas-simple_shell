#include "head_shelly.h"
/**
 * _strdup - a lot of things will happen
 *
 * @str: string
 *
 * Return: NULL str
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
