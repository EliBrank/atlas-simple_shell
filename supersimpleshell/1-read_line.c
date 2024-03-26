#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *buffer;
	size_t bufsize = 4096;

	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

  printf("$ ");
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
