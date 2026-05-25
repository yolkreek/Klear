#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum _Data_Type;
typedef int64_t K_Int; //only integer. size of 8bytes.
typedef double K_Float; // float and double included. 8byte size


typedef enum _Data_Type
{
	DATA_TYPE_NULL = 0,
	DATA_TYPE_INT,
	DATA_TYPE_FLOAT,
	DATA_TYPE_STR,
	DATA_TYPE_OBJ,
	DATA_TYPE_PTR,
	DATA_TYPE_UNDEFINED,
} Data_Type;
