#include "tree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Tree* tree_create()
{
	Tree* t = (Tree*)malloc(sizeof(Tree));
	if (t == NULL) return NULL;
	t->num_of_nodes = 0;
	t->root = NULL;

	return t;
}

Tree* tree_create_with_root(Tree_node* root)
{
	Tree* t = (Tree*)malloc(sizeof(Tree));
	if (t == NULL) return NULL;
	t->num_of_nodes = 1;
	t->root = root;

	return t;
}


Tree_node* tnode_create()
{
	Tree_node* tn = (Tree_node*)malloc(sizeof(Tree_node));
	tn->data = data_create_null();
	tn->left = NULL;
	tn->parent = NULL;
	tn->right = NULL;
	return tn;
}

bool tree_is_empty(const Tree* t)
{
	return t->num_of_nodes == 0;
}

bool tnode_is_root(const Tree_node* tn)
{
	return tn->parent == NULL;
}

bool tnode_no_child(const Tree_node* tn)
{
	return tn->right == NULL && tn->left == NULL;
}

void tree_set_root(Tree* t, Data data)
{
	Tree_node* root = tnode_create();
	root->data = data;
	t->root = root;
	t->num_of_nodes++;
}

void tree_add(Tree* t, Tree_node* tn, Data data, int r_or_l)
{
	if (tree_is_empty(t))
	{
		tree_set_root(t, data);
		return;
	}
	else
	{
		Tree_node* new_tnode = tnode_create();
		if (new_tnode == NULL) return;
		new_tnode->data = data;
		new_tnode->parent = tn;

		if (r_or_l == T_LEFT)
		{
			if (tn->left) printf("Already Exists.\n");
			else { tn->left = new_tnode; t->num_of_nodes++; };
		}
		else if (r_or_l == T_RIGHT)
		{
			if (tn->right) printf("Already Exists.\n");
			else { tn->right = new_tnode; t->num_of_nodes++; };
		}
		else
			printf("Input Right or Left.\n");
	}
}


Tree_node* tree_explore(Tree* t, const char* direction) //direction for example: "lrlrlrlrlllr"
{
	Tree_node* cur = t->root;
	int how_many = strlen(direction);

	for (int i = 0; i < how_many; i++)
	{
		if (direction[i] == 'l' || direction[i] == '<')
		{
			if (cur->left == NULL) { cur = NULL; break; }
			cur = cur->left;
		}
		else if (direction[i] == 'r' || direction[i] == '>')
		{
			if (cur->right == NULL) { cur = NULL; break; }
			cur = cur->right;
		}
		else {} //ignore 
	}

	return cur;
}

Stack* tree_DFS(Tree* t)
{
	if (t == NULL || tree_is_empty(t)) return NULL;

	Tree_node* cur = t->root;
	Stack* s = stack_create(t->num_of_nodes);
	Stack* order = stack_create(t->num_of_nodes); //Tree_node 구조체 포인터들이 들어갈 것임.

	stack_push(s, data_create_obj(t->root));

	while (!stack_is_empty(s))
	{
		Tree_node* popped_one = (Tree_node*)data_get_obj(stack_pop(s));
		stack_push(order, data_create_obj(popped_one));

		Tree_node* poppeds_r = popped_one->right;
		Tree_node* poppeds_l = popped_one->left;

		if (poppeds_r != NULL) stack_push(s, data_create_obj(poppeds_r));
		if (poppeds_l != NULL) stack_push(s, data_create_obj(poppeds_l));

	}


	stack_kill(&s);

	return order;
}
