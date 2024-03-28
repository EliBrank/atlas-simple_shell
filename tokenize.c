#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
/**
 * tokenize - tonkenizes function
 * 
 *@buffer: string to be tokenized
 *
 * Return: Array
*/

char **tokenize(char *buffer)
{
	int argCount = 0;
	char **array;
	char *portion;
	long unsigned int i, j;
	/* first delimiter to check is space, then newline */
	char *delim = " \n";

	/* gets num of args (strings) in buffer by counting spaces */
	argCount = arg_count(buffer);

	/* allocate memory for array to store tokenized input */
	array = (char **)malloc(sizeof(char *) * (argCount + 1));
	if (array == NULL)
	{
		free(buffer);
		exit(-1);
	}

	/* first strtok to initialize */
	portion = strtok(buffer, delim);

	/* strtok user input and store tokenized portions in array */
	i = 0;
	while (portion != NULL)
	{
		array[i] = strdup(portion);
		if (array[i] == NULL)
		{
			/* free everything (up to failed strdup alloc) by looping through */
			for (j = 0; j < i; j++)
				free(array[j]);
			free(array);
			free(buffer);
			exit(1);
		}
    /* update portion to next token from input */
		portion = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	return (array);
}