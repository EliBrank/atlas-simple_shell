#include "head_shelly.h"

/**
 * env_setup - formats environment into linked list 
 * @environ: environement array to process 
 *
 * Return: head pointer for new environment linked list, NULL if failure
 */
env_t *env_setup(char **environ)
{
    env_t *env_list = NULL;
    env_t *new = NULL;
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        env_convert_to_node(environ[i]);
        env_prepend_node(&env_list, environ[i]);
    }

    return (env_list);
}
