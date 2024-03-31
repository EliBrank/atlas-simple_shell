#include "head_shelly.h"

/**
 * env_prepend_node - adds environment variable node to linked list
 * @head: first node in env var linked list
 * @var: key-value pair to assign to prepended node
 *
 * Return: head node with new variable added, NULL on failure
 */
env_t *prepend_env_node(env_t **head, char *var)
{
	env_t *new_env = env_convert_to_node(var);

	if (head == NULL)
	{
		*head = new_env;
		return(*head);
	}

	new_env->next = *head;
	*head = new_env;

	return (*head);
}
