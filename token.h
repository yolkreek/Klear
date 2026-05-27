#pragma once

typedef struct _String_Stream String_stream;
typedef struct _String_Stream Parse_stream;

struct _String_Stream
{
	char* buffer;
	int length;
	int position;
};

char** tokenization(char* code);
Parse_stream* parse_stream_create(char* buffer);
void parse_stream_init(Parse_stream* ps, char* buffer);
char parse_stream_peek(Parse_stream* ps);
char parse_primary(Parse_stream* ps);

