#include "monty.c"

/**
* _rotr -  rotates the stack to the bottom
* @stack: head
* @line_number: line number
* Return: void
*/
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	stack_t *lst = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (lst->next != NULL)
		lst = lst->next;

	lst->prev->next = NULL;
	lst->prev = NULL;
	lst->next = curr;
	curr->prev = lst;
	*stack = lst;
}
