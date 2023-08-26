#include "monty.h"

/**
 * f_mul - Multiplies the second top element of the stack with the top element.
 * @stack: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_mul(stack_t **stack, unsigned int counter)
{
	stack_t *top, *second_top;
	/*Check if there are at least two elements in the stack*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/*Get references to the top and second top elements*/
	top = *stack;
	second_top = top->next;
	/*Multiply the second top element by the top element and update the second top*/
	second_top->n *= top->n;
	*stack = second_top;
	second_top->prev = NULL;
	free(top);/*Remove the top element from the stack*/
}
