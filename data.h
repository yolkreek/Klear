#pragma once
#include "data_type.h"
#include <stdint.h>
typedef union _rawData rawData;
typedef struct _Data Data;

union _rawData
{
	int i;
	float f;
	char* s;	//32bit: 4bytes, 64bit: 8bytes
	void* obj;	//32bit: 4bytes, 64bit: 8bytes
};

struct _Data
{
	Data_Type type;
	rawData r_data;
};


int K_int(int i);
int K_float(float f);
