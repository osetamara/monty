#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy, *last;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	copy = *head;
	last = *head;

	while (last->next != NULL)
	{
		last = last->next;
	}
	last->prev->next = NULL;
	last->next = copy;
	copy->prev = last;
	*head = last;
}
