#include "monty.h"

/**
 * f_pall - prints all the elements in the stack.
 * @head: stack head
 * @counter: not used
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	/*Unused parameter to avoid compiler warnings*/
	(void)counter;

	h = *head;
	/*Check if the stack is empty*/
	if (h == NULL)
		return;
	/*Traverse the stack and print its elements*/
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
