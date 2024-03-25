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
	char *buffer;
	ssize_t bytes;
	char **userArgs;
	int count = 0;

	/* allocate mem for buffer */
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
    /* create fork, execute tokenized input as command */
    forkexec(userArgs);
		if (strcmp(buffer, "exit\n") == 0)
			break;
	}

	free(buffer);


}

char **tokenize(char *buffer)
{
	char **array;
	char *portion;
	int i, j;
	/* first delim to check is space, then newline */
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

	/* strtok user input and store tokenized portions in array */
  i = 0;
	while (portion != NULL)
	{
		array[i] = strdup(portion);
		if (array[i] == NULL)
		{
			/* free everything by looping through */
			for (j = 0; j < i; j++)
				free(array[j]);
			free(array);
			free(buffer);
			return (-1);
		}
		portion = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
  return (array);
}

void forkerec(char **userArgs)
{
  child_pid = fork();
  if (child_pid == -1)
  {
    perror("failed to fork");
    return (-1);
  }
  if (child_pid == 0)
  {
    if (execve(userArgs[0], userArgs, NULL) == -1)
      perror("Error");
  }
  else
{
    wait(&status);
  }
}
