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
	int i = 0;

	newStr = malloc(sizeof(char) * strlen(str) + 1);
	if (newStr == NULL)
	{
		perror("Error: failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim[0])
		{
			newStr[i] = ' ';
		}
		else /* ARA: added else to copy the old string into the new string */
			newStr[i] = str[i];
	}

	return (newStr);
}
