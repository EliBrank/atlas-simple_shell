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
    env_t *new_env = NULL;

    if (head == NULL)
        return(NULL);

    new_env = malloc(sizeof(head));

    if (new_env == NULL)
        return (NULL);

    new_env->var = malloc(strlen(var) + 1);

    if (new_env->var == NULL)
    {
        free(new_env);
        return (NULL);
    }

    strcpy(new_env->var, var);
    new_env->next = *head;
    new_env->len = strlen(var);

    *head = new_env;

    return (*head);
}
