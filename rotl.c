#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;
	/*Check if the stack is empty or has only one element*/
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	/*Get the second element in the stack*/
	aux = (*head)->next;
	aux->prev = NULL;
	/*Traverse to the last element of the stack*/
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	/*Update the connections to rotate the stack to the top*/
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
