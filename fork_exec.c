#include "head_shelly.h"

/**
 * fork_exec - forks to parent and child
 * @user_args: double pointer
 *
 * Return: 0
 */
int fork_exec(char *exec_name, char **user_args, char **env, int *status)
{
	int forkVal;

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
		if (execve(exec_name, user_args, env) == -1)
		{
			perror("Error");
			return (-1);
		}
	}
	/* parent process waits for child to finish execution */
	wait(status);

	return (0);
}
