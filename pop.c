#include "monty.h"

/**
 * f_pop - removes the top element from the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;
	/*Check if the stack is empty*/
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;/*Store the current head*/

	*head = h->next;/* Update the head to the next element*/
	free(h);/*Free the previous top element*/
}
