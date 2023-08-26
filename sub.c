#include "monty.h"

/**
 * f_sub - subtracts the top element from the second top element of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	/*Count the number of nodes in the stack*/
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	/*Check if there are at least two elements in the stack*/
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;/*Store the current head*/
	/*Subtract the top element from the second top element*/
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;/*Update the stack head*/
	free(aux);/*Free the previous top element*/
}
