#pragma once
#include "data_type.h"
typedef union _Data Data;

union _Data
{
	int i;
	float f;
	char* s;
};

int get_data_int(const Data* n);
float get_data_float(const Data* n);
char* get_data_str(const Data* n);