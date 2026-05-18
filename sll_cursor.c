#include "sll_cursor.h"

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