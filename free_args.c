#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
/**
 * free_args - frees string in array
 * 
 *@userArgs: double pointer
  *
*/

void free_args(char **userArgs)
{
	int i;
  
  /* frees each string in array, then array itself */
	for (i = 0; userArgs[i] != NULL; i++)
		free(userArgs[i]);
	free(userArgs);
}