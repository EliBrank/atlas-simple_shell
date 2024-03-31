#include "head_shelly.h"

/**
 * main - gets, processes input for shelly
 *
 * Return: 0 if success, -1 if failure
 */
int main(void)
{
    /* extern char **environ; */
    char *buffer;
    size_t bufsize = 4096;
    char **userArgs;
    ssize_t bytes;
    char *path_value;
    char *newArgOne;
    char *tmp;

    /* set up environment */
    extern char **environ;
    char *env = env_setup(environ);
    /* allocate memory for buffer */
    buffer = (char *)malloc(sizeof(char) * bufsize);
    if (buffer == NULL)
        return (-1);

    /* central loop to get user input */ 
    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");
        bytes = getline(&buffer, &bufsize, stdin);
        if (bytes == -1)
        {
            free(buffer);
            return (-1);
        }
        /* exit loop if "exit" is entered */
        if (strcmp(buffer, "exit\n") == 0)
            break;
        /* split user input into individual strings (tokenize) */
        userArgs = tokenize(buffer);
        if (userArgs == NULL)
            continue;
        path_value = env_get(env);
        paths_array = tokenize();

        newArgOne = find_executable(userArgs[0], path_value);
        if (strcmp(userArgs[0], newArgOne) != 0)
        {
            if (strlen(newArgOne) > strlen(userArgs[0]))
            {
                /* reallocate memory for the first string */
                tmp = realloc(userArgs[0], (strlen(newArgOne) + 1) * sizeof(char));
                if (tmp == NULL)
                {
                    perror("Error: failed memory allocation");
                    exit(-1);
                }
                userArgs[0] = tmp;
            }
        }
        strcpy(userArgs[0], newArgOne);

        /* create fork, execute tokenized input as command */
        /* frees everything if fork or exec fails */
        if (fork_exec(userArgs) == -1)
        {
            free_args(userArgs);
            free(buffer);
            exit(-1);
        }
        free_args(userArgs);
    }

    free(buffer);
    return (0);
}
