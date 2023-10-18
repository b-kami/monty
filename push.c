#include "main.h"
/**
 * f_push - Adds a node to the stack
 * @head: The stack head
 * @counter: The line_number
 * Return: No return value
*/
void f_push(stack_t **head, unsigned int counter)
{
    int n, ji = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            ji++;
        for (; bus.arg[ji] != '\0'; ji++)
        {
            if (bus.arg[ji] > 57 || bus.arg[ji] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    n = atoi(bus.arg);
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
