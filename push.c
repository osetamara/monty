#include "monty.h"

/**
 * f_push - add node to the stack
 * @stack: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **stack, unsigned int counter)
{
	int n, l = 0, flag = 0;
	/*Check if the argument for push is provided*/
	if (bus.arg)
	{
		/*Check if the argument is a negative number*/
		if (bus.arg[0] == '-')
			l++;
		/*Check if the argument contains only digits*/
		for (; bus.arg[l] != '\0'; l++)
		{
			if (bus.arg[l] > 57 || bus.arg[l] < 48)
				flag = 1;
		}
		/*If the argument is not a valid integer*/
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/*Convert the argument to an integer*/
	n = atoi(bus.arg);
	/*Add the integer to the stack or queue based on bus.lifi*/
	if (bus.lifi == 0)
		addnode(stack, n);/*Add to stack*/
	else
		addqueue(stack, n);/*Add to queue*/
}
