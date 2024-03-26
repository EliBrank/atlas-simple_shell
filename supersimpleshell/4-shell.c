#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 *
 */

char **tokenize(char *buffer);
int forkexec(char **userArgs);

int main(void)
{
	char *buffer;
	size_t bufsize = 4096;
	char **userArgs;

	/* allocate mem for buffer */
	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

	/* central loop to get user input */
	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
    /* exit loop if "exit" is entered */
		if (strncmp(buffer, "exit", 4) == 0)
			break;
		/* split user input into indiv strings (tokenize) */
		userArgs = tokenize(buffer);
    /* create fork, execute tokenized input as command */
    forkexec(userArgs);
	}

	free(buffer);

  return (0);
}

char **tokenize(char *buffer)
{
	int argCount = 0;
	char **array;
	char *portion;
	long unsigned int i, j;
	/* first delim to check is space, then newline */
	char *delim = " \n";

	/* gets num of args (strings) in buffer by counting spaces */
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ' ')
			argCount++;
	}
	/* accounts for final word in buffer */
  /* looks at last char in buffer to check if space */
	if (buffer[strlen(buffer) - 1] != ' ')
		argCount++;

	/* allocate mem for array to store tokenized input */
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
			/* free everything by looping through */
			for (j = 0; j < i; j++)
				free(array[j]);
			free(array);
			free(buffer);
			exit(1);
		}
		portion = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
  return (array);
}

int forkexec(char **userArgs)
{
  int forkVal;
  int status;

  /* fork start */
  forkVal = fork();
  if (forkVal == -1)
  {
    perror("failed to fork");
    exit(-1);
  }
  /* child process (runs executable) */
  if (forkVal == 0)
  {
    if (execve(userArgs[0], userArgs, NULL) == -1)
    {
      perror("Error");
      exit(-1);
    }
  }
  /* parent process waits for child to finish execution */
  else
    wait(&status);

  return (0);
}
