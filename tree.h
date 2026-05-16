#pragma once

#define T_LEFT 0
#define T_RIGHT 1

#include <stdbool.h>

typedef struct tree
{
	int data;
	struct tree* parent;
	struct tree* left;
	struct tree* right;
} Tree;

Tree* tree_create();
bool tree_is_root(const Tree* t);
bool tree_is_empty(const Tree* t);
void tree_add(Tree* t, int data, int type); //use T_LEFT or T_RIGHT for type parameter
