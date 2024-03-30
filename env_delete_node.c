#include "head_shelly.h"

/**
 * get_env - deletes environment variable matching input string
 * @head: first node in linked list
 * @env_var: name of environment variable to delete
 *
 * Return: 0 if success, -1 if failure
 */
int env_delete_node(env_t **head, char *env_var)
{
    env_t *tmp = NULL;
    env_t *prev = NULL;

    if (*head == NULL)
        return (-1);

    tmp = *head;

    /* traverse list, look for node matching env_var */
    while (tmp != NULL || strcmp(tmp->env_var, env_var) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    /* if tmp is NULL, then the variable to delete was not found */
    if (tmp == NULL)
        return (-1);

    /* connect nodes around the deletion */
    /* if prev is NULL, then the variable was found at the beginning */
    if (prev == NULL)
        *head = tmp->next;
    else
        prev->next = tmp->next;

    /* delete the node */
    free(tmp->env_var);
    free(tmp);

    return (0);
}
