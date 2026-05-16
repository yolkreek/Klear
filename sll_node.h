#pragma once

#include "node.h"

typedef struct _SLL_Node SLL_Node;

struct _SLL_Node
{
	Node node;
	SLL_Node* next_node;
};

SLL_Node* sllnode_get_nextnode(SLL_Node* sn);
bool sllnode_is_tail(SLL_Node* sn);
