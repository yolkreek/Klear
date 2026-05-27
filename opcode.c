#include "opcode.h"
#include <string.h>

void op_push(Stack* s, Data data)
{
	stack_push(s, data);
}

Data op_pop(Stack* s)
{
	return stack_pop(s);
}

void op_store(Stack* s, Symbol_Table* st, char* name, Data data)
{
	int index = _op_lookup_symbol(st, name);

	if (index == -1)
	{
		Symbol_Node* new_symbol = &(Symbol_Node) { .sname = name, .stype = SYMBOL_TYPE_VAR, .address = (Data*)malloc(sizeof(Data))}; //일단은 VAR로 하자 CONST랑 FUNC도 생각하면 머리 터질 거 같음 ♥
		SLL_Node* new_node = sllnode_create(data_create_obj(new_symbol));
		*(new_symbol->address) = data;
	
		sll_append(st->table, new_node); 
	}
	else
	{
		SLL_Node* the_node = sll_node_get_by_index(st->table, index);
		Symbol_Node* the_symbol = (Symbol_Node*)data_get_obj(the_node->data);
		*(the_symbol->address) = data;
	}
	
}

Data op_load(Stack* s, Symbol_Table* st, char* name)
{
	int index = _op_lookup_symbol(st, name);

	if (index == -1)
	{
		exit(123456789);
	}
	else
	{
		SLL_Node* the_node = sll_node_get_by_index(st->table, index);
		Symbol_Node* the_symbol = (Symbol_Node*)data_get_obj(the_node->data);
		return *(the_symbol->address);
	}
}

void op_add(Stack* s)
{
	Data data1 = op_pop(s);
	Data data2 = op_pop(s);
	Data result;

	if (data_get_type(data1) == DATA_TYPE_INT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_int(data_get_int(data1) + data_get_int(data2));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(data_get_int(data1) + data_get_float(data2));
		else exit(111111);
	}
	else if (data_get_type(data1) == DATA_TYPE_FLOAT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_float(data_get_float(data1) + data_get_int(data2));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(data_get_float(data1) + data_get_float(data2));
		else exit(222222);
	}
	else exit(333333);

	op_push(s, result);
}

void op_sub(Stack* s)
{
	Data data1 = op_pop(s);
	Data data2 = op_pop(s);
	Data result;

	if (data_get_type(data1) == DATA_TYPE_INT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_int(-data_get_int(data1) + data_get_int(data2));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(-data_get_int(data1) + data_get_float(data2));
		else exit(111111);
	}
	else if (data_get_type(data1) == DATA_TYPE_FLOAT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_float(-data_get_float(data1) + data_get_int(data2));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(-data_get_float(data1) + data_get_float(data2));
		else exit(222222);
	}
	else exit(333333);

	op_push(s, result);
}

void op_mul(Stack* s)
{
	Data data1 = op_pop(s);
	Data data2 = op_pop(s);
	Data result;

	if (data_get_type(data1) == DATA_TYPE_INT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_int(data_get_int(data1) * data_get_int(data2));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(data_get_int(data1) * data_get_float(data2));
		else exit(111111);
	}
	else if (data_get_type(data1) == DATA_TYPE_FLOAT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_float(data_get_float(data1) * data_get_int(data2));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(data_get_float(data1) * data_get_float(data2));
		else exit(222222);
	}
	else exit(333333);

	op_push(s, result);
}

void op_div(Stack* s)
{
	Data data1 = op_pop(s);
	Data data2 = op_pop(s);
	Data result;

	if (data_get_type(data1) == DATA_TYPE_INT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_int(data_get_int(data2) / data_get_int(data1));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(data_get_float(data2) / data_get_int(data1));
		else exit(111111);
	}
	else if (data_get_type(data1) == DATA_TYPE_FLOAT)
	{
		if (data_get_type(data2) == DATA_TYPE_INT) result = data_create_float(data_get_int(data2) / data_get_float(data1));
		else if (data_get_type(data2) == DATA_TYPE_FLOAT) result = data_create_float(data_get_float(data2) / data_get_float(data1));
		else exit(222222);
	}
	else exit(333333);

	op_push(s, result);
}

void op_dup(Stack* s)
{
	Data _ = stack_peek(s);
	stack_push(s, _);
}

void op_swap(Stack* s)
{
	Data top = stack_peek(s);
	stack_pop(s);
	Data second_top = stack_pop(s);
	stack_push(s, top);
	stack_push(s, second_top);
}

static int _op_lookup_symbol(Symbol_Table* st, char* name)
{
	SLL_Node* cur = st->table->head_node;
	int index = 0;
	for (; index < st->table->num_of_nodes; index++)
	{
		char* compare_name = ((Symbol_Node*)data_get_obj(cur->data))->sname;
		if (strcmp(compare_name, name) == 0)
		{
			return index;
		}

	}


	return -1; //not found
}