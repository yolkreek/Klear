#pragma once
#include "ast.h"
#include "token.h"

//ASTree ast_create(char* code)
//{
//
//	code = tokenization(code);
//
//	Parse_stream* ps = parse_stream_create();
//	AST_node* cur = NULL;
//	if (ps == NULL) return (ASTree) { 0 };
//
//	parse_stream_init(ps, code);
//
//	for (int i = 0; i < ps->length; i++)
//	{
//		char c = parse_primary(ps);
//		cur = astnode_create();
//		switch (c)
//		{
//		case ASTNODE_TYPE_NUM: cur->
//
//		}
//	}
//
//}

AST_node* astnode_create()
{
	AST_node* astn = (AST_node*)malloc(sizeof(AST_node));

	astn->data.literal = data_create_null();
	astn->left = NULL;
	astn->right = NULL;
	astn->parent = NULL;
	return astn;
}

ASTN_type of_what_type_astnode(char c) //일단 지금은 테스트용이니까 변수 이름은 한 문자밖에 안되고 한 자리 숫자 셈밖에 안됨.
{
	if (c >= '0' && c <= '9') return ASTNODE_TYPE_NUM;
	else if (c == 'a' || c == 'b' || c == 'c') return ASTNODE_TYPE_VAR;
	
	else if (c == '+' || c == '-' || c == '*' || c == '/') return ASTNODE_TYPE_BIN_OP;
	else return 123123;
}


