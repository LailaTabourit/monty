#include "monty.h"

/**
* _rotr -  rotates the stack to the bottom
* @stack: head
* @line_number: line number
* Return: void
*/
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (curr->next != NULL)
		curr = curr->next;

	curr->prev->next = NULL;
	curr->prev = NULL;
	curr->next = *stack;
	(*stack)->prev = curr;
	*stack = curr;
}
