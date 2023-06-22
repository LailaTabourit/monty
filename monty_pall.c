#include "monty.h"

/**
* _pall - prints all the elements of stack
* @stack: head stack
* @line_number:line number
* by: Laila & Mega
* Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	(void)line_number;

	curr = *stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
