#include "node.h"
#include <stdio.h>
#include <stdlib.h>



Node* node_create(Data_Type type, Data data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->type = type;
	n->data = data;
}

Data_Type node_get_type(const Node* n)
{
	if (n == NULL) return NULL;
	return n->type;
}

Data* node_get_data(const Node* n)
{
	if (n == NULL) return NULL;

	switch (node_get_type(n))
	{
	case DATA_TYPE_UNDEFINED: return NULL;
	default: return &(n->data);
	}
}





