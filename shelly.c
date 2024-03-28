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