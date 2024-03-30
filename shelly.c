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
    ssize_t bytes;
    int env_size;

    /* set up environment */
    extern char **environ;
    char *env = env_setup(environ);
    /* allocate memory for buffer */
    buffer = (char *)malloc(sizeof(char) * bufsize);
    if (buffer == NULL)
        return (-1);

    /* central loop to get user input */ 
    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");
        bytes = getline(&buffer, &bufsize, stdin);
        if (bytes == -1)
        {
            free(buffer);
            return (-1);
        }
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

		/* exit loop if "exit" is entered */
		if (strcmp(buffer, "exit\n") == 0)
			break;
		/* split user input into individual strings (tokenize) */
		userArgs = tokenize(buffer);
    if (userArgs == NULL)
      continue;

	/* see if file exists and is exacutable by comparing strings in path and userargs*/
	char* find_executable(const char* arg, const char* paths[])
	{
	
	int i = 0;
	int len = strlen(str);

	if (arg == NULL || paths == NULL)
		return (NULL);

	str = (char *)malloc(sizeof(char) * len + 1)
	while (path[i] != NULL)
	{
		sprintf(str, "%s/%s", paths[i], arg[0]);
		if (access(str, X_OK))
		{
			return (str);
		}
		i++;
	}
	free (str);
	return (NULL);

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
