#include "head_shelly.h"

/**
 * fork_exec - forks to parent and child
 * @user_args: double pointer
 *
 * Return: 0
 */
int fork_exec(char **user_args)
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
		if (execve(user_args[0], user_args, NULL) == -1)
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
