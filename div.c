#include "monty.h"

/**
 * f_div - divides the second top element by the top element of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;/*Store the current head*/
	/*Check if the divisor (top of the stack) is zero*/
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Divide the second top element by the top element*/
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;/*Update the stack head*/
	free(h);/*Free the previous top element*/
}
