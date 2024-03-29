#include "head_shelly.h"

/**
 * get_env - retrieves environment variable matching input string
 * @env_var: name of environment variable to check for
 *
 * Return: value of environment variable if found, else NULL
 */
prepend_env_node(env_t **head, char *var)
{
  env_t *tmp = (env_t *)malloc(sizeof(env_t));
  env_t *ptr;

  tmp->var = item;
  tmp->next = NULL;
  if (*head == NULL)
      *head = tmp;
  else
  {
      ptr = *head;
      while (ptr->next != NULL)
          ptr = ptr->next;
      ptr->next = tmp;
  }
}
