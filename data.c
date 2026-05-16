#include "data.h"
#include <stdio.h>

int get_data_int(const Data* n)
{
	return n->i;
}

float get_data_float(const Data* n)
{
	return n->f;
}

char* get_data_str(const Data* n)
{
	return n->s;
}
