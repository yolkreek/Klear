#pragma once
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define CODE_LENGTH 500
static char* _get_var(Parse_stream* ps);
static char* _get_num(Parse_stream* ps);
static char* _get_op(Parse_stream* ps);
static char* _get_split_unit(Parse_stream* ps);
static char* _get_memory_str(size_t size);
static bool _var_name_condition(char c);
static bool _is_num(char c);
static bool _is_alpha_or_underbar(char c);
static bool _is_op(char c);
static bool _is_split_unit(char c);

char** tokenization(char* code)
{

	char* tokens[CODE_LENGTH] = { NULL, };
	int num_of_tokens = 0;
	Parse_stream* ps = parse_stream_create(code);

	while (ps->length != ps->position)
	{
		char peek = parse_stream_peek(ps);
		if (_is_alpha_or_underbar(peek)) tokens[num_of_tokens++] = _get_var(ps);
		else if (_is_num(peek)) tokens[num_of_tokens++] = _get_num(ps);
		else if (_is_op(peek)) tokens[num_of_tokens++] = _get_op(ps);
		else if (_is_split_unit(peek)) tokens[num_of_tokens++] = _get_split_unit(ps);
		else parse_primary(ps);
	}
	free(ps);
	return tokens;
}

Parse_stream* parse_stream_create(char* buffer)
{
	Parse_stream* ps = (Parse_stream*)malloc(sizeof(Parse_stream));
	if (ps == NULL) return NULL;

	parse_stream_init(ps, buffer);

	return ps;
}

void parse_stream_init(Parse_stream* ps, char* buffer) //not gonna modify src buffer so just let it be.
{
	ps->buffer = buffer;
	ps->length = strlen(buffer);
	ps->position = 0;
}

char parse_stream_peek(Parse_stream* ps)
{
	return ps->buffer[ps->position];
}

char parse_primary(Parse_stream* ps)
{
	return ps->buffer[ps->position++];
}

void free_tokens(char** tokens)
{
	for (int i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
}

static char* _get_var(Parse_stream* ps)
{
	char* varname = _get_memory_str(10);
	int savepoint = ps->position;
	char c = 0;
	do
	{
		c = parse_primary(ps);
		varname[ps->position - savepoint - 1] = c;
	} while (_var_name_condition(parse_stream_peek(ps)));

	return varname;
}

static char* _get_num(Parse_stream* ps)
{
	char* num = _get_memory_str(20);
	int savepoint = ps->position;
	char c = 0;
	do
	{
		c = parse_primary(ps);
		num[ps->position - savepoint - 1] = c;
	} while (_is_num(parse_stream_peek(ps)));

	return num;
}

static char* _get_op(Parse_stream* ps)
{
	char* num = _get_memory_str(4);

	char c = 0;
	c = parse_primary (ps);
	num[0] = c;
	if ((c == '+') && (parse_stream_peek(ps) == '+')) num[1] = parse_primary(ps);
	else if ((c == '-') && (parse_stream_peek(ps) == '-')) num[1] = parse_primary(ps);

	return num;
}

static char* _get_split_unit(Parse_stream* ps)
{
	char* su = _get_memory_str(1);
	su[0] = parse_primary(ps);

	return su;
}

static char* _get_memory_str(size_t size)
{
	return (char*)calloc(size + 1, sizeof(char));
}

static bool _var_name_condition(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

static bool _is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static bool _is_alpha_or_underbar(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

static bool _is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

static bool _is_split_unit(char c)
{
	return (c == '\n' || c == ';');
}