#include "head_shelly.h"

/**
 * free_string_array - frees strings in array, then array
 * @str_array: pointer to array of strings to free
 */
void free_string_array(char **str_array)
{
	int i;

	/* frees each string in array, then array itself */
	for (i = 0; str_array[i] != NULL; i++)
		free(str_array[i]);
	free(str_array);
}
