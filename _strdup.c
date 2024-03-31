#include "head_shelly.h"

/**
 * _strdup - duplicates string
 * @str: string to be duplicated
 *
 * Return: pointer to duplicated string, NULL if failure
 */
char *_strdup(char *str)
{
	char *dupStr;
	int i;
	int len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	dupStr = malloc(sizeof(char) * len + 1);

	if (dupStr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dupStr[i] = str[i];

	dupStr[i] = '\0';

	return (dupStr);
}

