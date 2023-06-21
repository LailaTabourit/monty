#include "monty.h"

/**
* _init_instructions - Find the appropreate function
* by: Laila and Mega
* Return: nothing
*/
instruction_t *_init_instructions(void)
{
	static instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{NULL, NULL}
	};

	return (instructions);
}
