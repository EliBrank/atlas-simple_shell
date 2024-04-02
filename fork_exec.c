#include "head_shelly.h"

/**
 * fork_exec - forks to parent and child
 * @exec_name: name of executable
 * @user_args: double pointer
 * @env: environment to be used for execution
 * @status: status code to be updated by wait
 *
 * Return: 0 if success, else -1
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
