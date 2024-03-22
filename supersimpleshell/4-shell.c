#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 */

int main(void)
{
	char *buffer;
	size_t bufsize = 4095;
	int i, j, count;
	char *buffer;
	ssize_t bytes;
	char **userArgs;

	/* init count, allocate mem for buffer */
	count = 0;
	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

	/* gets num of args (strings) in buffer by counting spaces */
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ' ')
			count++;
	}
	/* accounts for final word in buffer */
	if (buffer[strlen(buffer) - 1] != ' ')
		count++;

	/* central loop to get user input */
	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		printf("%s", buffer);
		/* split user input into indiv strings (tokenize) */
		userArgs = tokenize(buffer);
		if (strncmp(buffer, "exit", 4) == 0)
			break;
	}

	free(buffer);


}

char **tokenize(char *buffer)
{
	char **array;
	char *portion;
	char *delim = " \n";

	/* allocate mem for array to store tokenized input */
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
	{
		free(buffer);
		return (-1);
	}

	/* first strtok to initialize */
	portion = strtok(buffer, delim);
	i = 0;
	while (portion != NULL)
	{
		array[i] = strdup(portion);
		if (array[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(array[j]);
			free(array);
			free(buffer);
			return (-1);
		}
		printf("%s\n", array[i]);
		portion = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
}
