#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *aux;/*Temporary pointer to traverse the list*/

	aux = stack;/*Store the head to not lose the reference*/
	/*Traverse the list and free each node*/
	while (stack)
	{
		aux = stack->next;/* Store the next node*/
		free(stack);/* Free the current node*/
		stack = aux;/*Move to the next node*/
	}
}
