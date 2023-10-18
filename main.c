#define _POSIX_C_SOURCE 200809L
#include "main.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - The monty code interpreter
 * @argc: The number of arguments
 * @argv: The monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content = NULL;
    FILE *file = NULL;
    size_t size = 0;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&content, &size, file) != -1)
    {
        bus.content = content;
        counter++;
        execute(content, &stack, counter, file);
        free(content);
        content = NULL;
    }

    if (content != NULL)
        free(content);

    free_stack(stack);
    fclose(file);
    return (0);
}
