#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

Data data_create_raw(Data_Type type, K_Int i)      //caution: you can put all types of data with this func, EXCEPT for number(float, double) type datas.
{													//and make sure to type cast.
	return (Data) { .type = type, .r_data = { .i = i } };
}

Data data_create_int(K_Int i)
{
	return (Data) { .type = DATA_TYPE_INT, .r_data = { .i = i } };
}

Data data_create_float(K_Float f)
{
	return (Data) { .type = DATA_TYPE_FLOAT, .r_data = { .f = f } };
}

Data data_create_obj(void* obj)
{
	return (Data) { .type = DATA_TYPE_OBJ, .r_data = { .obj = obj } };
}

Data data_create_str(char* str)
{
	return (Data) { .type = DATA_TYPE_STR, .r_data = { .s = str } };
}

Data data_create_ptr(void* peter)
{
	return (Data) { .type = DATA_TYPE_PTR, .r_data = { .ptr = peter } };
}

Data data_create_null()
{
	return (Data) { .type = DATA_TYPE_NULL, .r_data = { .i = 0 } };
}

void data_copy(Data* dest, const Data* src)
{
	if (dest == NULL || src == NULL) return;
	dest->type = src->type;
	dest->r_data = src->r_data;
}

void data_swap(Data* dest, Data* src)
{
	if (dest == NULL || src == NULL) return;
	Data _ = *dest;
	dest->type = src->type;
	dest->r_data = src->r_data;

	src->type = _.type;
	src->r_data = _.r_data;
}

K_Int data_get_raw(const Data data) //no num
{
	if (data.type == DATA_TYPE_NULL) return 0;
	return data.r_data.i;
}

K_Int data_get_int(const Data data)
{
	if (data.type == DATA_TYPE_NULL) return 0;
	return data.r_data.i;
}

K_Float data_get_float(const Data data)
{
	if (data.type == DATA_TYPE_NULL) return 0.;
	return data.r_data.f;
}

char* data_get_str(const Data data)
{
	if (data.type == DATA_TYPE_NULL) return 0;
	return data.r_data.s;
}

void* data_get_obj(const Data data)
{
	if (data.type == DATA_TYPE_NULL) return 0;
	return data.r_data.obj;
}

void* data_get_ptr(const Data data)
{
	if (data.type == DATA_TYPE_NULL) return 0;
	return data.r_data.ptr;
}

Data_Type data_get_type(const Data n)
{
	return n.type;
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


