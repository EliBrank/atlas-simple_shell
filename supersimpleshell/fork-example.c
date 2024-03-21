#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *
 */

int main(void)
{
	pid_t og_pid;
	pid_t fork_pid;
	printf("Before fork\n");

	fork_pid = fork();
	if (fork_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	printf("After fork\n");
	og_pid = getpid();
	printf("My pid is %u, and for me, fork is: %u\n", og_pid, fork_pid);
	return (0);
}
