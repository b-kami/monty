#include "main.h"
/**
 * f_pint - prints the top of the stack
 * @head: The stack head
 * @counter: The line_number
 * Return: No return value
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
