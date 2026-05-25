#include <stdio.h>
#define CODE_LENGTH 5000

int main(int argc, char* argv)
{
	char* code[CODE_LENGTH] = { '\0', };

	fread(code, sizeof(char), CODE_LENGTH, stdin);

	printf("%s", code);

	
	return 0;
}