#include "head_shelly.h"

/**
 * tokenize - tokenizes function
 * @str: string to be tokenized
 *
 * Return: Array
 */
char **tokenize(char *str, char *delim)
{
    int argCount = 0;
    char **array;
    char *portion;
    long unsigned int i, j;
    char *newStr;

    /* converts delimiter in string to spaces if something else */
    if (strchr(str, ' ') == NULL)
    {
        newStr = _strdup(delim_to_space(str, delim));
        if (newStr == NULL)
        {
            perror("Error");
            free(str);
            exit(-1);
        }
    }
    else
        newStr = str;

    /* gets num of args in str by counting spaces */
    argCount = arg_count(newStr);
    if (argCount == 0)
    {
        return (NULL);
    }

    /* allocate memory for array to store tokenized input */
    array = (char **)malloc(sizeof(char *) * (argCount + 1));
    if (array == NULL)
    {
        perror("Error");
        free(newStr);
        exit(-1);
    }

    /* first strtok to initialize */
    portion = strtok(str, delim);

    /* strtok user input and store tokenized portions in array */
    i = 0;
    while (portion != NULL)
    {
        array[i] = strdup(portion);
        if (array[i] == NULL)
        {
            perror("Error");
            /* free everything (up to failed strdup alloc) by looping through */
            for (j = 0; j < i; j++)
                free(array[j]);
            free(array);
            free(str);
            exit(1);
        }
        /* update portion to next token from input */
        portion = strtok(NULL, delim);
        i++;
    }
    array[i] = NULL;
    return (array);
}
