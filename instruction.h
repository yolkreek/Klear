#pragma once
#include "opcode.h"

typedef struct _Instruction_line Instruction;

struct _Instruction_line
{
	Opcode opcode;
	Data operand_1;
	Data operand_2;
	//Data operand_3;
};