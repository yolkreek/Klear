#pragma once
#include "singly_linked_list.h"

typedef enum _Symbol_Type Symbol_Type;
typedef struct _Symbol Symbol_Node;
typedef struct _Symbol_Table Symbol_Table;

enum _Symbol_Type
{
	SYMBOL_TYPE_VAR,
	SYMBOL_TYPE_CONST,
	SYMBOL_TYPE_FUNC,
};

struct Symbol_Node
{
	Symbol_Type stype;
	char* sname;
};

struct _Symbol_Table //symbol_node objects' SLL
{
	int num_of_nodes;
	SLL* table;
};