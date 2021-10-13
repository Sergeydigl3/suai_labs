#include <stdio.h>
#include <stdlib.h>
#include "../../code_snippets.c"
// Написать программу, составляющую по двум символьным файлам линейные упорядоченные списки различных слов и функцию конкатенации списков. Выдать объединенный список на экран.


int main(int argc, char *argv[])
{
	file_s *s1 = read_file("mylabs/lab06/t1.txt");
	file_s *s2 = read_file("mylabs/lab06/t2.txt");

	list_t l1, l2, lmerge;
	init(&l1);init(&l2);init(&lmerge);
	
	readstr(s1->arr, s1->size, &l1);
	readstr(s2->arr, s2->size, &l2);

	merge_list_t(&l1, &lmerge);
	// merge_list_t(&l2, &lmerge);

	sort_list_size(&lmerge, 0);
	print_list(&lmerge);


	destroy(&l1);destroy(&l2);destroy(&lmerge);
	free(s1);free(s2);

	return 0;
}