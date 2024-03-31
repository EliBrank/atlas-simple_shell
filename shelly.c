#include "head_shelly.h"

/**
 * main - gets, processes input for shelly
 *
 * Return: 0 if success, -1 if failure
 */
int main(int argc, char **argv, char **envp)
{
	char **user_args;
	ssize_t bytes;
	char *buffer, *path_value_full, *new_arg_one;
	size_t bufsize = 4096;

	/* argc and argv aren't necessary, so cast as void */
	(void)argc;
	(void)argv;

	/* allocate memory for buffer */
	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);

	/* central loop to get user input */
	while (1)
	{
		/* check for interactive mode */
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

		/* tokenize user input into individual strings */
		user_args = tokenize(buffer);
		if (user_args == NULL)
			continue;
		path_value = env_get(envp);

		new_arg_one = find_executable(user_args[0], path_value);
		replace_arg_one(&(user_args[0]), new_arg_one);

		/* create fork, execute tokenized input as command */
		/* frees everything if fork or exec fails */
		if (fork_exec(user_args) == -1)
		{
			free_string_array(user_args);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		free_string_array(user_args);
	}
	free(buffer);
	return (0);
}
