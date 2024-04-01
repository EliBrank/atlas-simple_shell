#include "head_shelly.h"

/**
 * free_string_array - frees strings in array, then array
 * @str_array: pointer to array of strings to free
 */
void free_string_array(char **str_array)
{
	int i = 0;

	/* frees each string in array, then array itself */
	while (str_array[i])
	{
		free(str_array[i]);
		str_array[i] = NULL;
		i++;
	}
	free(str_array);
	str_array = NULL;
}
