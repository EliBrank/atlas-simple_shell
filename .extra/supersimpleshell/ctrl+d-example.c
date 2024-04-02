#include <stdio.h>
#include <stdlib.h>

int main() {
    char *input = NULL;
    size_t input_size = 0;
    ssize_t characters_read;

    printf("Enter lines of text (press Ctrl+D to finish):\n");

    while ((characters_read = getline(&input, &input_size, stdin)) != -1) {
        printf("You entered: %s", input);
    }

    free(input);

    printf("End of input reached.\n");

    return 0;
}

