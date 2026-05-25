#pragma once
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Stack Stack;

typedef struct _Stack
{
	Data* stack;
	int size;
	int sp; //stack pointer
} Stack;

Stack* stack_create(int size);
void stack_print_info(const Stack* s);
void stack_print(const Stack* s);
Data stack_pop(Stack* s);
void stack_push(Stack* s, Data data);
void stack_extend(Stack* s);
bool stack_is_empty(const Stack* s);
bool stack_is_full(const Stack* s);
Data stack_peek(const Stack* s);
void stack_clear(Stack* s);
void stack_kill(Stack** s);


