#include "monty.h"

/**
 * f_mod - Computes rest of division of second top element by top element.
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_mod(stack_t **stack, unsigned int counter)
{
	stack_t *top, *second_top;
	/*Check if there are at least two elements in the stack*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/*Get references to the top and second top elements*/
	top = *stack;
	second_top = top->next;
	/*Check for division by zero*/
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/*Calculate remainder and update the second top element*/
	second_top->n %= top->n;
	*stack = second_top;
	second_top->prev = NULL;
	free(top);
}
