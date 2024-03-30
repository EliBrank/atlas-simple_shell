#include "head_shelly.h"

/**
 * env_convert_to_node - creates node from key/value pair
 * @keyValuePair: key/value pair from environ to break apart 
 *
 * Return: pointer to new node containing variable and its value
 */
env_t *env_convert_to_node(char *keyValuePair)
{
  char *delim = "=";

  env_node->var = strtok(keyValuePair, delim);
  if (env_node->var == NULL)
  {
    free(env_node);
    perror("Error");
    exit(-1);
  }
  env_node->value = strtok(NULL, delim);
  if (env_node->value == NULL)
  {
    free(env_node->var);
    free(env_node);
    perror("Error: value not found");
    exit(-1);
  }

  env_node->next = NULL;

  return (env_node);
}
