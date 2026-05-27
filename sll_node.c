#include "sll_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

SLL_Node* sllnode_create(Data data)
{
	SLL_Node* sn = (SLL_Node*)malloc(sizeof(SLL_Node));
	sn->data = data;
	sn->next_node = NULL;

	return sn;
}

SLL_Node* sllnode_get_nextnode(SLL_Node* sn)
{
	if (sn == NULL) return NULL;

	if (!sllnode_is_tail(sn))
		return sn->next_node;
	else return NULL;

}

bool sllnode_is_tail(SLL_Node* sn)
{
	return sn->next_node;
}



