#pragma once
#include "data.h"
#include "data_type.h"
#include <stdbool.h>

typedef struct _Node Node;

typedef enum _Node_Type Node_Type; 

struct _Node
{
	Data_Type type;
	Data data;
};

enum _Node_Type
{
	NODE_TYPE_NULL,
	NODE_TYPE_HEAD,
	NODE_TYPE_BODY,
	NODE_TYPE_TAIL,
	NODE_TYPE_WHOLE // is of head and tail - SLL that has only one node.

};

Node* node_create(Data_Type type, Data data);
Data_Type node_get_type(const Node* n);
Node* node_get_data(const Node* n);

Node* node_get_nextnode(const Node* n);
