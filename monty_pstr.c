#include "monty.h"
/**
* _pstr - prints the string starting at the top of the stack,
* by: laila and mega
* @stack: head
* @line_number: number line
* Return: void
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	while (curr != NULL && curr->n != 0 && curr->n >= 0 && curr->n <= 127)
	{
		if (curr->n != 0)
			putchar(curr->n);
		curr = curr->next;
	}
	putchar('\n');
}

