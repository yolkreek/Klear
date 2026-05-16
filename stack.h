#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Stack Stack;

typedef struct _Stack
{
	int* stack;
	int size;
	int sp;
} Stack;

Stack stack_create(int size);
void stack_print_info(const Stack* s);
void stack_print(const Stack* s);
int stack_pop(Stack* s);
void stack_push(Stack* s, int data);
void stack_extend(Stack* s);
bool stack_is_empty(const Stack* s);
bool stack_is_full(const Stack* s);
int stack_peek(const Stack* s);
void stack_destroy(Stack* s);


