#include "monty.h"

/**
 * push - push a value onto the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *argument = strtok(NULL, " \n");

	if (!argument || !is_numeric(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);
	add_node(stack, value);
}

/**
 * pall - print all elements in the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the Monty file
 */
void pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
