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
	char **array;
	char *buffer, *portion;
	ssize_t bytes;
	char *delim = " \n";

	/* init count, allocate mem for buffer */
	count = 0;
	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

	/* counts args (strings) in buffer */
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ' ')
			count++;
	}
	if (buffer[strlen(buffer) - 1] != ' ')
		count++;

	/* central loop to get user input */
	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		printf("%s", buffer);
		if (strncmp(buffer, "exit", 4) == 0)
			break;
	}




	free(buffer);


}
