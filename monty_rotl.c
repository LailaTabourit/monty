#include "monty.h"
/**
* _rotl - rotates the stack to the top.
* @stack:head of the stack
* @line_number: line number
* Return: void
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	stack_t *lst = *stack;
	(void)line_number;

	if (*stack == NULL  || (*stack)->next == NULL)
		return;
	while (lst->next != NULL)
		lst = lst->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	lst->next = curr;
	curr->prev = lst;
	curr->next = NULL;
}

