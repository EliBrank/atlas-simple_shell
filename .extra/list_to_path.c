#include "head_shelly.h"

/**
 * list_to_path - converts linked list into NULL-terminated array of strings
 * @list: linked list to be converted
 *
 * Return: pointer to array
 */
char **list_to_path(env_t *list)
{
	int count = 0;
	env_t *tmp = list;
	char **array;
	int i, j;
	char *new_value = NULL;

	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}

	array = (char**)malloc((count + 1) * sizeof(char*));
	if (array == NULL)
	{
		perror("Error: failed memory allocation");
		exit("EXIT FAILURE");
	}

	tmp = list;
	for (i = 0; i < count; i++)
	{
		new_value = realloc()
		array[i] = strdup(new_value, );
		if (array[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free(array[j]);
			free(array);
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
	}
}
