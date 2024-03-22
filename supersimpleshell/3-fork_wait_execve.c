#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	int i;
	int numProc;
	int status;

	char *procArgs[] = {"/bin/ls", "-l", "/tmp/", NULL};

	numProc = 5;

	for (i = 0; i < numProc; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("failed to fork");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(procArgs[0], procArgs, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}

