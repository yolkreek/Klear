#include "singly_linked_list.h"

SLL* sll_create()
{
	SLL* s = (SLL*)malloc(sizeof(SLL));
	s->num_of_nodes = 0;
	s->cursor = NULL;
	s->cursor_index = -1;
	s->head_node = NULL;
	return s;
}

void sll_clear(SLL* s)
{
	if (s == NULL) return;
	if (s == sll_is_empty(s)) return;

	SLL_Node* crrnt_node = s->head_node;
	SLL_Node* next_node = crrnt_node->next_node;

	while (next_node != NULL)
	{
		free(crrnt_node);
		crrnt_node = next_node;
		next_node = crrnt_node->next_node;
	}

	free(crrnt_node);

	s->cursor = NULL;
	s->cursor_index = -1;
	s->head_node = NULL;
	s->num_of_nodes = 0;

}

void sll_kill(SLL** s)
{
	sll_clear(*s);
	free(&s);

	*s = NULL;
}

bool sll_is_empty(const SLL* s)
{
	return s->num_of_nodes == 0;
}

//void sll_print_info(SLL* const s)
//{
//
//
//	if (sll_node_type(s) == NODE_TYPE_EMPTY) printf("The SLL is empty.\n");
//	else
//	{
//		int i = 1;
//		SLL* current_node = s;
//
//		while (1)
//		{
//			char* freethis = sll_data2str(current_node);
//			printf("#%d node's type is %s\n", i, sll_type2str(current_node));
//			printf("#%d node's data is %s\n\n", i++, freethis);
//			free(freethis);
//			current_node = current_node->next_node;
//			if (current_node == NULL) break;
//		}
//	}
//}
//
//
//
//
//void sll_print_node(SLL* const s)
//{
//	switch (sll_node_type(s))
//	{
//	case NODE_TYPE_EMPTY: printf("The SLL is empty.\n"); break;
//	default: printf("")
//
//	}
//}

void sll_append(SLL* s, SLL_Node* sn)
{
	if (s == NULL || sn == NULL) return;

	SLL_Node* last_node = sll_get_last_node(s);

	if (last_node == NULL)
		s->head_node = sn;
	else
		last_node->next_node = sn;

	s->num_of_nodes++;
	return;

}

void sll_pop(SLL* s)
{
	if (s == NULL) return;
	if (sll_is_empty(s)) return;
	if (s->num_of_nodes == 1)
	{
		sll_clear(s);
		return;
	}

	SLL_Node* second_last_node = s->head_node;
	for (int i = 0; i < s->num_of_nodes - 2; i++)
		second_last_node = second_last_node->next_node;

	free(second_last_node->next_node);
	second_last_node->next_node = NULL;
	s->num_of_nodes--;
}

SLL_Node* sll_get_last_node(SLL* s)
{
	SLL_Node* last_node = s->head_node;
	for (int i = 0; i < s->num_of_nodes - 1; i++)
		last_node = sllnode_get_nextnode(last_node->next_node);

	return last_node;
}

Node_Type sll_node_type(const SLL* s, const SLL_Node* n)
{
	if (n == NULL) return NODE_TYPE_NULL;

	if (sll_is_empty(s))
		return NODE_TYPE_NULL;
	
	if (s->num_of_nodes == 1 && n == s->head_node) return NODE_TYPE_WHOLE;

	if (n == s->head_node)
		return NODE_TYPE_HEAD;
	else
	{
		if (n->next_node == NULL) return NODE_TYPE_TAIL;
		else return NODE_TYPE_BODY;
	}
}












