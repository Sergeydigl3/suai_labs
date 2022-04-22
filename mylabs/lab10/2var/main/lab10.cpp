#include "lab10.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
size_t file_size(FILE *f)
{
	// https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
	fseek(f, 0, SEEK_END);	 // seek to end of file
	size_t fsize = ftell(f); // get current file pointer
	fseek(f, 0, SEEK_SET);	 // seek back to beginning of file
	return fsize;
}
[[nodiscard]] file_s *read_file(const char *filename)
{
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("Error! opening files\n");
		exit(1);
	}

	size_t fsize = file_size(f);
	char *s = (char *)malloc(fsize * sizeof(char));
	for (size_t i = 0; i < fsize; i++)
		s[i] = fgetc(f);

	file_s *tstur = (file_s *)malloc(sizeof(file_s));
	
	tstur->arr = s;
	tstur->size = fsize;
	fclose(f);
	return tstur;
}