#pragma once
#define STR_SIZE 3

typedef struct file_s
{
	char *arr;
	int size;
} file_s;

typedef struct oper_s
{
	char *op;
	int count;
	int size;
} oper_s;

file_s *read_file(const char *filename);