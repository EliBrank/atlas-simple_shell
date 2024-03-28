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

	len = _strlen(str);

	new = malloc(len * sizeof(char) + 1);
	if (new == NULL)
		return (NULL);

	new = _strncpy(new, str, len);

	return (new);
}




/**
 * _strlen - returns the length of a string
 *
 * @s : int
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int x;

	x = 0;

	while (s[x] != '\0')
	{
		x++;
	}

	return (x);
}

/**
 * _strncpy - write a function that copies a string
 *
 * @dest : destination
 * @src : string
 * @n : end
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a;

	for (a = 0; src[a] != '\0' && a < n; a++)
	{
		dest[a] = src[a];
	}
	for (; a < n; a++)

	dest[a] = '\0';

	return (dest);
}