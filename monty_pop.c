#include "monty.h"
/**
* _pop - prints the top of stack
* @stack: stack
* @line_number: line_number
* Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	*stack = head->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(head);
}
