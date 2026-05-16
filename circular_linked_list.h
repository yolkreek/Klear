#pragma once

typedef struct _Circular_linked_list CLL;

typedef struct _Circular_linked_list
{
	int data;
	struct _Singly_linked_list* next_node;
} CLL;