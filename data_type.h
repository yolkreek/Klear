#pragma once
#include <stdio.h>
#include <stdlib.h>
enum _Data_Type;

typedef enum _Data_Type
{
	DATA_TYPE_NULL = 0,
	DATA_TYPE_INT,
	DATA_TYPE_FLOAT,
	DATA_TYPE_STR,
	DATA_TYPE_OBJ,
	DATA_TYPE_UNDEFINED,
} Data_Type;


