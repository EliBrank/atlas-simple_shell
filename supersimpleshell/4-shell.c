#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **tokenize(char *buffer);
int fork_exec(char **userArgs);
void free_args(char **userArgs);

int main(void)
{
	char *buffer;
	size_t bufsize = 4096;
	char **userArgs;

	/* allocate memory for buffer */
	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return -1;

	/* central loop to get user input */
	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		/* exit loop if "exit" is entered */
		if (strcmp(buffer, "exit\n") == 0)
			break;
		/* split user input into individual strings (tokenize) */
		userArgs = tokenize(buffer);
		/* create fork, execute tokenized input as command */
    /* frees everything if fork or exec fails */
		if (fork_exec(userArgs) == -1)
		{
			free_args(userArgs);
			free(buffer);
			exit(-1);
		}
		free_args(userArgs);
	}

	free(buffer);
	return 0;
}

char **tokenize(char *buffer)
{
	int argCount = 0;
	char **array;
	char *portion;
	long unsigned int i, j;
	/* first delimiter to check is space, then newline */
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

int fork_exec(char **userArgs)
{
	int forkVal;
	int status;

	/* fork start */
	forkVal = fork();
	if (forkVal == -1)
	{
		perror("Fork Failure");
		return (-1);
	}
	/* child process (runs executable) */
	if (forkVal == 0)
	{
		if (execve(userArgs[0], userArgs, NULL) == -1)
		{
			perror("Error");
			return (-1);
		}
	}
	/* parent process waits for child to finish execution */
	else
		wait(&status);

	return (0);
}

void free_args(char **userArgs)
{
	int i;
  
  /* frees each string in array, then array itself */
	for (i = 0; userArgs[i] != NULL; i++)
		free(userArgs[i]);
	free(userArgs);
}

