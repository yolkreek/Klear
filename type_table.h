#pragma once
#include "singly_linked_list.h"

//for variables and constants.

typedef struct _Type_Table Type_Table;
typedef struct _Type_Node Type_Node;

struct _Type_Node
{
	Data_Type dtype;
	char* dname;
};

struct _Type_Table
{
	SLL* table;
};