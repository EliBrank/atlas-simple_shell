#include "head_shelly.h"

/**
 * word_count - gets number of arguments based on number of spaces
 * @str: string to be checked
 * 
 * Return: wordCount 
 */
int arg_count(char *str)
{
	bool is_word = false;
	int wordCount = 0;
	int i;

	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			if (is_word == true)
			{
				wordCount++;
				is_word = false;
			}
		}
		else
		is_word = true;
	}
	if (is_word == true)
		wordCount++;

	return(wordCount);
}
