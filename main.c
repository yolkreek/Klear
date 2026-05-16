#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"

int main()
{
	Tree* tree = tree_create();
	tree_add(tree, 2, 12312312);
	tree_add(tree, 2, T_LEFT);
	tree_add(tree, 3, T_RIGHT);
	tree_add(tree->right, 4, T_RIGHT);
	tree_add(tree->right, 5, T_RIGHT);
	tree_add(tree->right, 6, T_LEFT);




	
	return 0;
}

