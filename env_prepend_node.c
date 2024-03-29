#include "head_shelly.h"

/**
 * get_env - adds environment variable node to linked list
 * @head: first node in env var linked list
 * @var: key-value pair to assign to prepended node
 *
 * Return: head node with new variable added, NULL on failure
 */
prepend_env_node(env_t **head, char *var)
{
  env_t *tmp = NULL;
  env_t *ptr = NULL;

  tmp = (env_t *)malloc(sizeof(env_t));

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
