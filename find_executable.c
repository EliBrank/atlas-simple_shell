#include "head_shelly.h"

/**
 * find_executable - checks if file exists and is executable
 * @arg: name of program to search for
 * @paths: array of directories from PATH
 *
 * Return: complete path for program if found, else NULL
 */
char* find_executable(char *arg, char **paths)
{
    int i = 0;
    int len = strlen(str);

    if (arg == NULL || paths == NULL)
        return (NULL);

    if (access(arg, X_OK))
        return (arg);

    str = (char *)malloc(sizeof(char) * len + 1);
    if (str == NULL)
    {
        perror ("Error: failed to allocate memory");
        exit(-1);
    }

    while (path[i] != NULL)
    {
        sprintf(str, "%s/%s", paths[i], arg);
        if (access(str, X_OK))
        {
            return (str);
        }
        i++;
    }
    free (str);
    return (NULL);
