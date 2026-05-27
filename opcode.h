#pragma once
#include "data.h"
#include "stack.h"
#include "symbol_table.h"
#include "type_table.h"

typedef enum _KOpcode
{
	OP_PUSH,
	OP_POP,
	OP_STORE,
	OP_LOAD,
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_DUP,
	OP_SWAP,
} Opcode;

void op_push(Stack* s, Data data);
Data op_pop(Stack* s);
void op_store(Stack* s, Symbol_Table* st, char* name, Data data);
Data op_load(Stack* s, Symbol_Table* st, char* name);
void op_add(Stack* s); 
void op_sub(Stack* s);
void op_mul(Stack* s);
void op_div(Stack* s);
void op_dup(Stack* s);
void op_swap(Stack* s);

