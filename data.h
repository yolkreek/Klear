#pragma once
#include "data_type.h"
#include <stdint.h>
typedef union _rawData rawData;
typedef struct _Data Data;


union _rawData
{
	K_Int i;
	K_Float f;
	char* s;	//32bit: 4bytes, 64bit: 8bytes
	void* obj;	//32bit: 4bytes, 64bit: 8bytes
	void* ptr;
};

struct _Data
{
	Data_Type type;
	rawData r_data;
};



Data data_create_raw(Data_Type type, K_Int i);
Data data_create_int(K_Int i);
Data data_create_float(K_Float f);
Data data_create_obj(void* obj);
Data data_create_str(char* str);
Data data_create_ptr(void* peter);
Data data_create_null();

void data_copy(Data* dest, const Data* src);
void data_swap(Data* dest, Data* src);

K_Int data_get_raw(const Data data);
K_Int data_get_int(const Data data);
K_Float data_get_float(const Data data);
char* data_get_str(const Data data);
void* data_get_obj(const Data data);
void* data_get_ptr(const Data data);
Data_Type data_get_type(const Data n);
