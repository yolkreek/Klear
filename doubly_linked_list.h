#pragma once

typedef struct _Doubly_linked_list DLL;

typedef struct _Doubly_linked_list
{
	int data;
	DLL* prev_node;
	DLL* next_node;
} DLL;
