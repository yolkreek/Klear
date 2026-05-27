#pragma once
#include "data.h"
#include "tree.h"

typedef enum _AST_type AST_type;
typedef struct _ASTree ASTree;
typedef struct _ASTree_node AST_node;
typedef union _AST_raw_data AST_rdata;
typedef struct _AST_data AST_data;

struct _ASTree
{
	int num_of_nodes;
	AST_node* root;
};

struct _ASTree_node
{
	AST_data data;

	AST_node* parent;
	AST_node* left;
	AST_node* right;

};

struct _AST_data
{
	union _AST_raw_data
	{
		Data literal;
		char* var;
		char binary_op;
	};
	
	AST_type type;
};



enum _AST_type
{
	AST_TYPE_NUM,
	AST_TYPE_VAR,
	AST_TYPE_UNI_OP,
	AST_TYPE_BIN_OP,
};


AST_node* astnode_create();
void astnode_init(AST_node* astn);

AST_type of_what_type_astnode(char c);
