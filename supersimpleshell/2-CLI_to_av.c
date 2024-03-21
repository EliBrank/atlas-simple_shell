#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int i, j;
	int count = 0;
	char **array;
	char *buffer;
	size_t bufsize = 4095;
	char *portion;
	char *delim = " \n";
	ssize_t bytes;

	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

	bytes = getline(&buffer, &bufsize, stdin);
	if (bytes == -1)
	{
		free(buffer);
		return (-1);
	}

	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ' ')
			count++;
	}
	if (buffer[strlen(buffer) - 1] != ' ')
		count++;


	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
	{
		free(buffer);
		return (-1);
	}

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

	for (i = 0; i < count; i++)
		free(array[i]);
	free(array);
	free(buffer);

	return (0);
}
