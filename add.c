#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;
	/*Count the number of elements in the stack*/
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	/*Check if there are at least two elements in the stack*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Reset the pointer to the stack head*/
	h = *head;
	/*Add the top two elements of the stack*/
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;/*Update the stack head*/
	free(h);/*Free previous top element*/
}
