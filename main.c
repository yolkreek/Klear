#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"

int main()
{
	Stack* steak = stack_create(10);
	Tree* tree = tree_create();

	tree_set_root(tree, data_create_int(50));
	tree_add(tree, tree->root, data_create_int(2), T_LEFT);
	tree_add(tree, tree->root, data_create_int(3), T_RIGHT);
	tree_add(tree, tree->root->left, data_create_float(5), T_RIGHT);
	tree_add(tree, tree->root->left, data_create_float(4), T_LEFT);
	tree_add(tree, tree->root->right, data_create_float(4.5), T_RIGHT);
	tree_add(tree, tree->root->right, data_create_float(97.5), T_LEFT);
	tree_add(tree, tree->root->right->left, data_create_str("ABC"), T_LEFT);
	tree_add(tree, tree_explore(tree, "><<"), data_create_ptr(0x12), T_RIGHT);
	Tree_node* test = tree_explore(tree, "><>>>>>>>");

	Stack* dfs = tree_DFS(tree);

	int p[5] = { 0, 1, 2, 3, 4 };
	printf("%d\n", sizeof(p));
	printf("%p\n", p);

	printf("%d", sizeof(so_raw));
	
	return 0;
}


