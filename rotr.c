#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @stack: stack 
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy, *last;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	copy = *stack;
	last = *stack;

	while (last->next != NULL)
	{
		last = last->next;
	}
	last->prev->next = NULL;
	last->next = copy;
	copy->prev = last;
	*stack = last;
}
