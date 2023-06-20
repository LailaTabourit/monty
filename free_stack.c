#include "monty.h"

/**
* _free_stack - Frees elements in the stack
* @stack: stack
* by: laila and mega
*/
void _free_stack(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *tmp;

	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*stack = NULL;
}
