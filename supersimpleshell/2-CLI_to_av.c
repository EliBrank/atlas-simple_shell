#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int i;
	char *array;
	char *buffer;
	size_t bufsize = 4096;
	char *portion;
	char *delimiter = " ";

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

	free(buffer);

	return (0);
}
