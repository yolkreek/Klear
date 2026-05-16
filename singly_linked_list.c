#include "singly_linked_list.h"

SLL* sll_create()
{
	SLL* s = (SLL*)malloc(sizeof(SLL));
	s->num_of_nodes = 0;
	s->cursor = NULL;
	s->head_node = NULL;

	return s;
}



SLL* sll_get_node_datatype(const SLL* s)
{
	if (s == NULL)
	{
		printf("Attempting to get next node of NULL.\n");
		return NULL;
	}
	return s->next_node;
}

SLL* sll_get_node_data(const SLL* s)
{
	if (s == NULL)
	{
		printf("Attempting to get next node of NULL.\n");
		return NULL;
	}
	return s->next_node;
}

SLL* sll_get_next_node(const SLL* s)
{
	if (s == NULL)
	{
		printf("Attempting to get next node of NULL.\n");
		return NULL;
	}

	if (sll_node_type == NODE_TYPE_EMPTY) return NULL;

	return s->next_node;
}

Node* sll_get_last_node(SLL* s)
{

	Node* last_node;
	if (sll_is_empty(s)) return NULL;

	sll_cursor_init(s);
	while (s->cursor->next_node != NULL)
		s->cursor = s->cursor->next_node;
	
	last_node = s->cursor;
	
	return last_node;
}

SLL* sll_delete_node(SLL* s)
{

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


void sll_append(SLL* sll, Data_Type type, void* data)
{
	SLL* s;
	SLL* last_node = sll_get_last_node(sll);

	s = (SLL*)calloc(1, sizeof(SLL));

	if (type == DATA_TYPE_INT)
	{
		s->type = DATA_TYPE_INT;
		s->data = (int*)malloc(sizeof(int));
		*(int*)s->data = (int)data;
	}
	/*else if (sll->type == FLOAT)
	{
		int n = 0;
		s->data = (float*)malloc(sizeof(float));
		*(float*)s->data = (float)data;
	}*/
	else if (type == DATA_TYPE_STR)
	{
		s->type = DATA_TYPE_STR;
		s->data = (char*)malloc((strlen((char*)data) + 1) * sizeof(char) );
		strcpy((char*)s->data, data);
	}
	else
	{
		printf("Unsupported Type.\n");
		exit(0);
	}

	if (last_node == NULL)
	{
		s->index = 0;
		*sll = *s;
	}
	else
	{
		s->index = last_node->index + 1;
		last_node->next_node = s;
	}

	return;

}

void sll_pop(SLL* s)
{
	SLL* last_node = sll_get_last_node(s);

}

void sll_clear(SLL* s)
{
	SLL* current_node = s;
	SLL* next_node = s->next_node;
	if (s->index == -1)
	{
		printf("How do I kill a dead?\n");
	}
	else if (s->index == 0)
	{
		if (!sll_is_empty(s))
		{
			while (current_node != NULL)
			{
				free(current_node->data);
				current_node = current_node->next_node;
			}	

			current_node = s;
			next_node = s->next_node;

			while (next_node != NULL)
			{
				current_node = next_node;
				next_node = current_node->next_node;
				free(current_node);			
			}

		}

		s->index = -1;
		s->type = DATA_TYPE_UNDEFINED;
		s->data = NULL;
		s->next_node = NULL;
	}
	else
	{
		printf("Input the head node.\n");
	}
}

void sll_kill(SLL** s)
{
	sll_clear(*s);
	free(&s);

	*s = NULL;
}

Node_type sll_node_type(SLL* s, const Node* n)
{
	if (n == NULL || s->num_of_nodes == 0) return NODE_TYPE_NULL;

	if (s->num_of_nodes == 1)
	{
		if (s->head_node == n) return NODE_TYPE_WHOLE;
		else return NODE_TYPE_NULL;
	}
	else
	{
		sll_cursor_init(s);
		if (s->head_node == n) return NODE_TYPE_HEAD;
	}
}

void sll_cursor_init(SLL* s)
{
	s->cursor = s->head_node;
}

bool sll_is_empty(const SLL* s)
{
	return s->num_of_nodes == 0;
}





