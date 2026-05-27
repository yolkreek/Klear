#pragma once

#include "data.h"
#include <stdbool.h>

typedef struct _SLL_Node SLL_Node;

struct _SLL_Node
{
	Data data;
	SLL_Node* next_node;
};

SLL_Node* sllnode_create(Data data);

SLL_Node* sllnode_get_nextnode(SLL_Node* sn);

bool sllnode_is_tail(SLL_Node* sn);

