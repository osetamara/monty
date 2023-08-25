#include "monty.h"

/**
 * pint - prints the top element of the stack
 * @stack: pointer to the linked list stack
 * @line_number: line number where the opcode occurs
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *loop;

	loop = *stack;
	/*Check if the stack is empty*/
	if (loop == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Print the top element of the stack*/
	printf("%d\n", loop->n);
}
