#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"
#include "sll_node.h"
#define _SLL_BUFFER_SIZE 20

typedef struct _Singly_linked_list SLL;

struct _Singly_linked_list
{
	int num_of_nodes;

	SLL_Node* cursor; 
	int cursor_index; 

	// more metadatas coming soon..
	SLL_Node* head_node;
};

SLL* sll_create();
void sll_clear(SLL* s);
void sll_kill(SLL** s);
bool sll_is_empty(const SLL* s);
void sll_print_info(const SLL* s);

void sll_append(SLL* s, SLL_Node* sn);
void sll_pop(SLL* s);
SLL_Node* sll_get_last_node(const SLL* s);

SLL_Node* sll_node_get_by_index(SLL* s, int index);




