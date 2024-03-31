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
	char **user_args;
	ssize_t bytes;
	char *path_value, *new_arg_one;

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
		user_args = tokenize(buffer);
		if (user_args == NULL)
			continue;
		path_value = env_get(env);
		paths_array = tokenize();

		new_arg_one = find_executable(user_args[0], path_value);
		replace_arg_one(&(user_args[0]), new_arg_one);

		/* create fork, execute tokenized input as command */
		/* frees everything if fork or exec fails */
		if (fork_exec(user_args) == -1)
		{
			free_args(user_args);
			free(buffer);
			exit(-1);
		}
		free_args(user_args);
	}

	free(buffer);
	return (0);
}
