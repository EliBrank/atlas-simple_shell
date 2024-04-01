#include "head_shelly.h"

/**
 * _isspace- find out if something is made up entirely of whitespace
 * @str: the string to check
 * 
 * Return: 0 if any not whitespace found, 1 if string is entirely whitespace
 */
int _isspace(char *str) 
{
    while (*str) 
	{
        if (*str != ' ' && *str != '\n' && *str != '\t')
		{
            return (0);
        }
		str++;
    }
    return (1);
}
