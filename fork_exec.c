#include "head_shelly.h"
/**
 * fork_exec - forks to parent and child
 * 
 *@userArgs: double pointer
 *
 * Return: 0
*/

int fork_exec(char **userArgs)
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
		if (execve(userArgs[0], userArgs, NULL) == -1)
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