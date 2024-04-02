#include "head_shelly.h"

void betty(void);

/**
 * main - gets, processes input for shelly
 * @argc: number of arguments (unused)
 * @argv: arguments passed with shell
 * @envp: array of environment variables for this function
 *
 * Return: 0 if success, -1 if failure
 */
int main(int argc, char **argv, char **envp)
{
	char **user_args, **path_value_array;
	ssize_t bytes;
	char *buffer, *path_value_full, *exec_name;
	size_t bufsize = 8192;
	int status = 0;

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
			break;
		
		/* built-ins */
		if (strcmp(buffer, "exit\n") == 0)
			break;
		if (strcmp(buffer, "env\n") == 0)
		{
			print_env(envp);
			continue;
		}

		/* check if user input consists only of spaces */
		if (_isspace(buffer) == 1)
			continue;

		/* tokenize user input into individual strings */
		user_args = tokenize(buffer, " \n");
		if (user_args == NULL)
			continue;
		
		/* get key/value pair from environment variable list */
		path_value_full = env_get(envp, "PATH");
		if (path_value_full != NULL)
			/* tokenize PATH value into array of strings */
			path_value_array = tokenize(path_value_full, ":");
		else
		{
			fprintf(stderr, "%s file not found\n", user_args[0]);
			continue;
		}

		/* looks for directories which contain executable name */
		exec_name = find_executable(user_args[0], path_value_array);
		free_string_array(path_value_array);

		/* create fork, execute tokenized input as command */
		/* frees everything if fork or exec fails */
		if (fork_exec(exec_name, user_args, envp, &status) == -1)
		{
			free(exec_name);
			free_string_array(user_args);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		free(exec_name);
		free_string_array(user_args);
	}
	free(buffer);

	/* WEXITSTATUS extracts exit value from wait output in forkexec */
	exit(WEXITSTATUS(status));
}
