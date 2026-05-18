#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int K_int(int i)
{
	return (int64_t)i;
}

int K_float(float f)
{

	void* _f = malloc(sizeof(float));
	if (_f == NULL) return 0;
	int64_t i = 0;

	memcpy(_f, &f, sizeof(float));
	i = *(int64_t*)_f;

	free(_f);


	return i;
}


Data* data_create(Data_Type type, int64_t r_data)
{
	Data* n = (Data*)malloc(sizeof(Data));
	if (n == NULL) return;
	n->type = type;
	n->r_data = r_data;

	return n;
}

Data_Type data_get_type(const Data* n)
{
	if (n == NULL) return DATA_TYPE_NULL;
	return n->type;
}

void data_modify(Data* n, rawData r_data)
{
	if (n == NULL || n->type == DATA_TYPE_UNDEFINED) return;

	n->r_data = r_data;
}

Data* data_get(const Data* n)
{
	if (n == NULL) return NULL;

	switch (data_get_type(n))
	{

	case DATA_TYPE_NULL: return NULL;
	case DATA_TYPE_INT: return n->data.i; break;
	case DATA_TYPE_FLOAT: return n->data.f; break;
	case DATA_TYPE_STR: return n->data.s; break;
	case DATA_TYPE_OBJ: return n->data.obj; break;
	default: return NULL;

	}
}

//char* node_data2str(const Node* s) //이거 node.c로 관리
//{
//	char* temp = NULL;
//	char* rtnstr = NULL;
//
//	if (s->type == DATA_TYPE_STR)
//	{
//		temp = (char*)malloc(strlen(s->data.s));
//		sprintf(temp, "%s", s->data.s);
//	}
//	else if (s->type == DATA_TYPE_INT)
//	{
//		temp = (char*)malloc(_NODE_BUFFER_SIZE);
//		sprintf(temp, "%d", s->data.i);
//	}
//	else if (s->type == DATA_TYPE_FLOAT)
//	{
//		temp = (char*)malloc(_NODE_BUFFER_SIZE);
//		sprintf(temp, "%f", s->data.f);
//	}
//	else if (s->type == DATA_TYPE_NULL)
//	{
//		sprintf(temp, "%s", "NULL");
//	}
//	else
//	{
//		sprintf(temp, "%s", "Undefined Data");
//	}
//
//	strcpy(rtnstr, temp);
//	free(temp);
//
//	return rtnstr;
//}
//
//const char* node_type2str(const Node* s) //이거 node.c로 관리
//{
//	return s->type == DATA_TYPE_INT ? "Integer" :
//		(s->type == DATA_TYPE_FLOAT ? "Float" :
//			(s->type == DATA_TYPE_STR ? "String" : "Undefined"));
//}


