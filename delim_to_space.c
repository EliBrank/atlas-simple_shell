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
    char *tmpStr;
    char *newStr;
    int len = strlen(delim);
    int i, j;

    tmpStr = _strdup(str);
    if (tmpStr == NULL)
    {
        return (NULL);
    }
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
