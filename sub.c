#include "monty.h"

/**
 * f_sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_sub(stack_t **stack, unsigned int counter)
{
	stack_t *top, *second_top;
	/*Check if there are at least two elements in the stack*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/*Get references to the top and second top elements*/
	top = *stack;
	second_top = top->next;
	/*Subtract top element from second top element update second top*/
	second_top->n -= top->n;
	*stack = second_top;
	second_top->prev = NULL;
	free(top);/*Remove the top element from the stack*/
}
