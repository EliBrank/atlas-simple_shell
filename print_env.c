#include <stdio.h>

/**
 * print_env - print environmental variables
 * @env: array of environment variables
 */
void print_env(char **env)
{
	int i = 0;
    while (env[i] != NULL) 
	{
        printf("%s\n", env[i]);
        i++;
    }
}
