#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pstr(stack_t **stack, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
