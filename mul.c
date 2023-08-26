#include "monty.h"

/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	/*Calculate the length of the stack*/
	while (h)
	{
		h = h->next;
		len++;
	}
	/*Check if there are at least 2 elements in the stack*/
	if (len < 2)
	{
		/*rint an error message and clean up before exiting*/
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Reset the stack pointer to the beginning*/
	h = *head;
	/*Calculate the product of the top two elements*/
	aux = h->next->n * h->n;
	/*Update the value of the second element with the product*/
	h->next->n = aux;
	/*Remove the original top element by moving the head pointer to the next element*/
	*head = h->next;
	/*Free the memory of the original top element*/
	free(h);
}
