#pragma once

#define T_LEFT 0
#define T_RIGHT 1

#include <stdbool.h>
#include "data.h"
#include "stack.h"

typedef struct _Tree Tree;
typedef struct _Tree_node Tree_node;

struct _Tree
{
	int num_of_nodes;
	Tree_node* root;
};


struct _Tree_node
{
	Data data;
	Tree_node* parent;
	Tree_node* left;
	Tree_node* right;
};


Tree* tree_create();
Tree_node* tnode_create();
bool tnode_is_root(const Tree_node* t);
bool tnode_no_child(const Tree_node* tn);
void tree_set_root(Tree* t, Data data);
bool tree_is_empty(const Tree* t);
void tree_add(Tree* t, Tree_node* tn, Data data, int r_or_l);  //use T_LEFT or T_RIGHT for type parameter
Tree_node* tree_explore(Tree* t, char* direction);
Stack* tree_DFS(Tree* t);




