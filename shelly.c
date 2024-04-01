#include "head_shelly.h"

/**
 * main - gets, processes input for shelly
 *
 * Return: 0 if success, -1 if failure
 */
int main(int argc, char **argv, char **envp)
{
	char **user_args, **path_value_array;
	ssize_t bytes;
	char *buffer, *path_value_full, *exec_name;
	size_t bufsize = 4096;
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

		if (strcmp(buffer, "exit\n") == 0)
			break;

		if (strcmp(buffer, "env\n") == 0)
		{
			print_env(envp);
			continue;
		}

		/* tokenize user input into individual strings */
		user_args = tokenize(buffer, " \n");
		if (user_args == NULL)
			continue;
		
		path_value_full = env_get(envp, "PATH");
		path_value_array = tokenize(path_value_full, ":");
		exec_name = find_executable(user_args[0], path_value_array);
		
		free_string_array(path_value_array);

		if (exec_name == NULL)
		{
			fprintf(stderr, "%s file not found\n", user_args[0]);
			continue;
		}
		/* create fork, execute tokenized input as command */
		/* frees everything if fork or exec fails */
		if (fork_exec(exec_name, user_args, envp, &status) == -1)
		{
			/* ARA: leak: exec_name must be freed here */
			free(exec_name);
			exec_name = NULL;
			free_string_array(user_args);
			free(buffer);
			buffer = NULL;
			exit(EXIT_FAILURE);
		}
		free(exec_name);
		exec_name = NULL;
		free_string_array(user_args);
	}
	free(buffer);
	buffer = NULL;
	exit(WEXITSTATUS(status));
}
