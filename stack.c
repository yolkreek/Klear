#include "stack.h"

Stack* stack_create(int size)
{
	if (size < 1) return;
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->size = size;
	s->stack = (Data*)malloc(size * sizeof(Data));
	memset(s->stack, 0, size * sizeof(Data));
	s->sp = -1;

	return s;
}

void stack_print_info(const Stack* s)
{
	if (s == NULL) return;
	printf("The pointer of stack: %p\n", s->stack);
	printf("Stack view: ");
	stack_print(s);
	printf("The size of stack: %d\n", s->size);
	printf("The stack pointer index of stack: %d\n\n", s->sp);
}

void stack_print(const Stack* s) //this views raw data.
{
	if (s == NULL) return;
	for (int i = 0; i <= s->sp; i++)
		printf("%d|", s->stack[i].r_data.i);
	printf("\n");
}

Data stack_pop(Stack* s)
{
	if (s == NULL) return data_create_null();
	return stack_is_empty(s) ? data_create_null() : s->stack[s->sp--];
}

void stack_push(Stack* s, Data data)
{
	if (stack_is_full(s))
		stack_extend(s);

	s->stack[++s->sp] = data;
	return;
}

void stack_extend(Stack* s)
{

	int* temp = (int*)malloc(s->size * 2 * sizeof(Data));
	memset(temp, 0, s->size * 2 * sizeof(int));
	memcpy(temp, s->stack, s->size * sizeof(int));

	s->size *= 2;

	free(s->stack);
	s->stack = temp;
}
bool stack_is_empty(const Stack* s)
{
	return s->sp == -1;
}
bool stack_is_full(const Stack* s)
{
	return s->sp == s->size - 1;
}

Data stack_peek(const Stack* s)
{
	return s->stack[s->sp];
}

void stack_clear(Stack* s)
{
	if (s == NULL) return;
	free(s->stack);
	s->stack = NULL;
	s->size = 0;
	s->sp = -1;
}

void stack_kill(Stack** s)
{
	if (s == NULL) return;
	stack_clear(*s);
	free(*s);
}
