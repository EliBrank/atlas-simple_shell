#include "head_shelly.h"

/**
 * delim_to_space - converts delimiter to spaces for a string
 * @str: string to process
 * @delim: delimiter to target for conversion
 * 
 * Return: processed string
 */
char *delim_to_space(char *str, char *delim)
{
    char *newStr;
    int len = strlen(delim);
    int i, j;

    tmpStr = _strdup(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (str[i] == delim[j])
            {
                newStr[i] = ' ';
            }
        }
    }

    return (newStr);
}
