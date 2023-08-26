#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
 */
void f_swap(stack_t **stack, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;
	/*Count the number of elements in the stack*/
	h = *stack;

	while (h)
	{
		h = h->next;
		len++;
	}
	/*Check if there are at least two elements in the stack*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;/*Store the current head*/
	/*Swap the values of the top two elements*/
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
