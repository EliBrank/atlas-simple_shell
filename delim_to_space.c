#include "head_shelly.h"

/**
 * delim_to_space - converts delimiter to spaces for a string
 * @str: string to process
 * @delim: delimiter to target for conversion
 * 
 * Return: processed string, NULL if failure
 */
char *delim_to_space(char *str, char *delim)
{
	char *newStr;
	int i;

	newStr = _strdup(str);
	if (newStr == NULL)
	{
		return (NULL);
	}
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim[0])
		{
			newStr[i] = ' ';
		}
	}

	return (newStr);
}
