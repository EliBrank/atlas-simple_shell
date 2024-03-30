#include "head_shelly.h"

/**
 * main - gets, processes input for shelly
 *
 * Return: 0 if success, -1 if failure
 */
int main(void)
{
  /* extern char **environ; */
	char *buffer;
	size_t bufsize = 4096;
	char **userArgs;

  /* set up environment */
  /* char **env = env_setup(environ); */

  /* allocate memory for buffer */
	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

	/* central loop to get user input */ 
	while (1)
	{
    if (isatty(STDIN_FILENO))
      printf("$ ");
		if (getline(&buffer, &bufsize, stdin) == -1);
      return (-1);
		/* exit loop if "exit" is entered */
		if (strcmp(buffer, "exit\n") == 0)
			break;
		/* split user input into individual strings (tokenize) */
		userArgs = tokenize(buffer);
    if (userArgs == NULL)
      continue;
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
	return (0);
}
