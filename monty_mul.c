#include "monty.h"
/**
* _mul - multiplies the second top element with the top of the stack.
* @stack: head
* @line_number: line number
* by: laila and mega
* Return: void
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}
