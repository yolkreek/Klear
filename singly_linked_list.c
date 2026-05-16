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

SLL_Node* sll_get_next_node(const SLL_Node* sn)
{
	return sn->next_node;
}

SLL_Node* sll_get_last_node(SLL* s)
{
	SLL_Node* last_node = s->head_node;
	for (int i = 0; i < s->num_of_nodes - 1; i++)
		last_node = sll_get_next_node(last_node->next_node);

	return last_node;
}

char* sll_data2str(const SLL* s) //YOU MUST FREE temp.
{
	char* temp = (char*)malloc(sizeof(char) * _SLL_BUFFER_SIZE);

	s->type == DATA_TYPE_INT ? sprintf(temp, "%d", *(int*)s->data) :
		(s->type == DATA_TYPE_FLOAT ? sprintf(temp, "%f", *(float*)s->data) :
			(s->type == DATA_TYPE_STR ? sprintf(temp, "%s", (char*)s->data) : sprintf(temp, "NULL")));

	return temp;
}

const char* sll_type2str(const SLL* s)
{
	return s->type == DATA_TYPE_INT ? "Integer" :
		(s->type == DATA_TYPE_FLOAT ? "Float" :
			(s->type == DATA_TYPE_STR ? "String" : "Undefined"));
}

void sll_print_node(SLL* const s)
{
	switch (sll_node_type(s))
	{
	case NODE_TYPE_EMPTY: printf("The SLL is empty.\n"); break;
	default: printf("")

	}
}

void sll_print_info(SLL* const s)
{


	if (sll_node_type(s) == NODE_TYPE_EMPTY) printf("The SLL is empty.\n");
	else
	{
		int i = 1;
		SLL* current_node = s;

		while (1)
		{
			char* freethis = sll_data2str(current_node);
			printf("#%d node's type is %s\n", i, sll_type2str(current_node));
			printf("#%d node's data is %s\n\n", i++, freethis);
			free(freethis);
			current_node = current_node->next_node;
			if (current_node == NULL) break;
		}
	}
}


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

Node_Type sll_node_type(SLL* s, const SLL_Node* n)
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


//cursor

void sll_cursor_init(SLL* s)
{
	if (sll_is_empty(s)) return;

	s->cursor = s->head_node;
	s->cursor_index = 0;
}

SLL_Node* sll_cursor_next(SLL* s)
{
	if (sll_cursor_is_overflow(s)) return NULL;

	s->cursor = s->cursor->next_node;
	s->cursor_index++;

	return s->cursor;
}

SLL_Node* sll_cursor_offset(SLL* s, int offset)
{
	if (s == NULL) return;

	if (sll_cursor_is_overflow(s) && offset >= 0) return s->cursor;
	if (sll_cursor_is_underflow(s) && offset <= 0) return s->cursor;

	int sllnode_index = s->cursor_index + offset;

	if (sllnode_index >= s->num_of_nodes) { sll_cursor_set_overflow(s); return s->cursor; }
	if (sllnode_index < 0) { sll_cursor_set_underflow(s); return s->cursor; }

	
	if (offset >= 0)
	{
		for (int i = 0; i < offset; i++)
			sll_cursor_next(s);
	}
	else
	{
		sll_cursor_init(s);
		for (int i = 0; i < sllnode_index; i++)
			sll_cursor_next(s);
	}

	return s->cursor;
	
}

SLL_Node* sll_cursor_set_by_node(SLL* s, SLL_Node* sn)
{
	sll_cursor_init(s);

	for (int i = 0; s->cursor != sn; i++)
		sll_cursor_next(s);

	return s->cursor;
	
}

SLL_Node* sll_cursor_set_by_index(SLL* s, int index)
{
	if (index < 0)
	{
		sll_cursor_set_underflow(s); 
		return s->cursor;
	}
	else if (index >= s->num_of_nodes)
	{
		sll_cursor_set_overflow(s);
		return s->cursor;
	}

	sll_cursor_init(s);

	for (int i = 0; i < index; i++)
		sll_cursor_next(s);

	return s->cursor;
}

SLL_Node* sll_cursor_return(SLL* s)
{
	return s->cursor;
}

bool sll_cursor_is_overflow(const SLL* s)
{
	return s->cursor == NULL || s->cursor_index == s->num_of_nodes;
}

void sll_cursor_set_overflow(SLL* s)
{
	s->cursor = NULL;
	s->cursor_index = s->num_of_nodes;
}

bool sll_cursor_is_underflow(const SLL* s)
{
	return s->cursor == NULL || s->cursor_index == -1;
}

void sll_cursor_set_underflow(SLL* s)
{
	s->cursor = NULL;
	s->cursor_index = -1;
}

void sll_cursor_validate(SLL* s)
{

}

bool sll_is_empty(const SLL* s)
{
	return s->num_of_nodes == 0;
}









