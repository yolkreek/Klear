#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Tree* tree_create()
{
	Tree* t = (Tree*)malloc(sizeof(Tree));
	t->parent = NULL;
	t->data = NULL;
	t->left = NULL;
	t->right = NULL;

	return t;
}

bool tree_is_root(const Tree* t)
{
	return t->parent == NULL;
}

bool tree_is_empty(const Tree* t)
{
	return t->parent == NULL && t->left == NULL && t->right == NULL && t->data == NULL;
}

void tree_add(Tree* t, int data, int type)
{

	if (tree_is_empty(t))
	{
		t->data = data;
	}
	else
	{
		Tree* new_t = tree_create();
		new_t->data = data;
		new_t->parent = t;
		if (type == T_LEFT)
			t->left ? printf("Already Exists.\n") : (t->left = new_t);
		
		else if(type == T_RIGHT)
			t->right ? printf("Already Exists.\n") : (t->right = new_t);
		else
			printf("Input Valid Type.\n");
		
	}
}

