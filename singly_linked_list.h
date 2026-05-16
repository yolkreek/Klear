#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data_type.h"
#include "sll_node.h"
#define _SLL_BUFFER_SIZE 20

typedef struct _Singly_linked_list SLL;

struct _Singly_linked_list
{
	int num_of_nodes;

	SLL_Node* cursor; // if cursor == null and cursor_index == -1,
	int cursor_index; // that means cursor is unavailable. (cursor is at start or sll is empty.)

	// more metadatas coming soon..
	SLL_Node* head_node;
};

SLL* sll_create();
Node_Type sll_node_type(SLL* s);
SLL* sll_get_node_datatype(const SLL* s);
SLL* sll_get_node_data(const SLL* s);
SLL* sll_get_next_node(const SLL* s);
SLL* sll_get_last_node(const SLL* s);
SLL* sll_delete_node(SLL* s);
char* sll_data2str(const SLL* s);
const char* sll_type2str(const SLL* s);
void sll_print_info(const SLL* s);
bool sll_is_empty(const SLL* s);
SLL* sll_lookup(const);
void sll_append(SLL* sll, Data_Type type, void* data);
void sll_pop(SLL* s);
void sll_clear(SLL* s);
void sll_kill(SLL** s);

Node_Type sll_node_type(const SLL* s, const Node* n);




