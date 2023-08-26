#include "monty.h"

/**
 * f_pint - prints the value at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	/*Check if the stack is empty*/
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Print the value at the top of the stack*/
	printf("%d\n", h->n);
}
