#include "head_shelly.h"

/**
 * env_get - retrieves environment variable matching input string
 * @env_list: list of environment variables to look through
 * @var: name of environment variable to check for
 *
 * Return: value of environment variable if found, else NULL
 */
char *env_get(env_t **env_list, char *var)
{
    env_t *tmp = NULL;
    env_t *prev = NULL;

    if (*env_list == NULL)
        return (-1);

    tmp = *env_list;

    /* traverse list, look for node matching var */
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
