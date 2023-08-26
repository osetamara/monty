#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @stack: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void f_rotl(stack_t **stack,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp, *last;
	/* Check if the stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	tmp = *stack;
	last = *stack;
	/* Traverse to find the last element of the stack */
	while (last->next != NULL)
	{
		last = last->next;
	}
       	/* Rearrange pointers to achieve rotation effect */
	last->next = tmp;
	tmp->prev = last;
	*stack = tmp->next;
	tmp->next = NULL;
	tmp->prev = NULL;
}
