#include "monty.h"


char *int_to_string(int number);
int is_numeric(char *str);

/**
 * push - push a node at the beginning of the structure
 * @stack: a stack struct
 * @line_number: num of line on monty file where
 * the opcode is written
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *argument;
	stack_t *new_node = malloc(sizeof(stack_t));

	argument = strtok(NULL, " \n");
	/*printf("argument inside push = %s\n", argument);*/
	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*printf("Argument = %s\n", argument);*/
	value = atoi(argument);
	/*printf("value is %d and argument is %s\n", value, argument);*/
	if (is_numeric(argument) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Push the value onto the stack.*/
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}


/**
 * is_numeric - check if a string only conatins numerics
 * @str: string to be checked
 *
 * Return: 0 success, -1 failure
 */

int is_numeric(char *str)
{
	int j = 0;

	str = strtok(str, " \n");
	if (str[0] == '-')
		j++;
	for (; str[j] != '\0'; j++)
	{
		/*printf("%c\n", str[i]);*/
		if (str[j] < '0' || str[j] > '9')
			return (-1);
	}
	return (0);
}


/**
 * int_to_string - chnage atoi result back into a string (testing)
 * @number: int to chnage to str
 *
 * Return: string literal
 */

char *int_to_string(int number)
{
	char *string = malloc(sizeof(char) * 10);

	sprintf(string, "%d\n", number);
	return (string);
}
