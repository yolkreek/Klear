#pragma once

#include "singly_linked_list.h"

void sll_cursor_init(SLL* s);
SLL_Node* sll_cursor_next(SLL* s);
SLL_Node* sll_cursor_offset(SLL* s, int offset);
SLL_Node* sll_cursor_set_by_node(SLL* s, SLL_Node* sn);
SLL_Node* sll_cursor_set_by_index(SLL* s, int index);
SLL_Node* sll_cursor_return(SLL* s);
bool sll_cursor_is_overflow(const SLL* s);
void sll_cursor_set_overflow(SLL* s);
bool sll_cursor_is_underflow(const SLL* s);
void sll_cursor_set_underflow(SLL* s);
