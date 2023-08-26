#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *aux;/*Temporary pointer to traverse the list*/

	aux = head;/*Store the head to not lose the reference*/
	/*Traverse the list and free each node*/
	while (head)
	{
		aux = head->next;/* Store the next node*/
		free(head);/* Free the current node*/
		head = aux;/*Move to the next node*/
	}
}
