#include "monty.h"

/**
* _init_instructions - Find the appropreate function to run the opcode instructions
* by: Laila and Mega
* Return : instruction
*/
instruction_t *init_instructions(void)
{
	static instruction_t instrucctions[] = {
		{"push", _push},
		{"pall", _pall},
	};

	return instructions;
}
