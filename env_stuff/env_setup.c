#include "head_shelly.h"

/**
 * setup_env - formats environment into linked list 
 * @environ: environement array to process 
 *
 * Return: head pointer for new environment linked list, NULL if failure
 */
char *env_setup(char **environ)
{
  env_t *env_list = NULL;
  int env_size = sizeof(environ) / sizeof(environ[0]);

  for (i = 0; i < env_size; i++)
  {
    prepend_env_node(&env_list, environ[i]);
  }
}
