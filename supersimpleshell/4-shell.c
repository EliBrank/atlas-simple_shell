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
	size_t bufsize = 4096;

	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		printf("%s", buffer);
		if (strncmp(buffer, "exit", 4) == 0)
			break;
	}

	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ' ')
			count++;
	}
	if (buffer[strlen(buffer) - 1] != ' ')
		count++;




	free(buffer);


}
