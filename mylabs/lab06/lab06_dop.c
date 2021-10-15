#include <stdio.h>
#include <stdlib.h>
#include "../../code_snippets.c"
// Написать программу, составляющую по двум символьным файлам линейные упорядоченные списки различных слов и функцию конкатенации списков. Выдать объединенный список на экран.

int main(int argc, char *argv[])
{
    file_s *s1 = read_file("mylabs/lab06/t1.txt");
    file_s *s2 = read_file("mylabs/lab06/t2.txt");

    list_t l1, l2, lmerge;
    init(&l1);
    init(&l2);
    init(&lmerge);

    readstr(s1->arr, s1->size, &l1);
    readstr(s2->arr, s2->size, &l2);

    merge_list_t(&l1, &lmerge);
    merge_list_t(&l2, &lmerge);

    // sort_list_size(&lmerge, 0);
    remove_duplicates(&lmerge);
    print_list(&lmerge);
    int act;
    scanf_s("%d", &act);

    switch (act)
    {
    case 1:
        // insert
        int index;
        printf("Enter index:");
        scanf("%d", &index);
        printf("\nEnter word: ");
        char st[100] = {0};
        char c = 0;
        int counter = 0;
        int flag = 0;
        while ((c = getchar()) != '\n' || flag == 0)
        {
            if (flag == 0){
                flag = 1;
            }
            else
                {
                    st[counter] = c;
                    counter++;
                }
        }
        int size = cstrlenc(st, 100);
        char *s = (char *)malloc(size * sizeof(char));
        for (size_t i = 0; i < size; i++)
        {
            s[i] = st[i];
        }
        node_t *gnode = get_node(&lmerge, index);
        insert(&lmerge, gnode, s, size, size);
        printf("Done!\n");
        print_list(&lmerge);
        break;

    case 2:
        int index;
        printf("Enter delete index: ");
        scanf_s("%d", &index);
        list_remove(&lmerge, index);
        printf("Done!\n");
        print_list(&lmerge);
        break;
        break;

    case 3:
        int from, to;
        printf("Enter delete index from to: ");
        scanf_s("%d %d", &from, &to);
        for (int i = 0; i < (to-from+1); i++)
        {
            list_remove(&lmerge, from);
        }
        printf("Done!\n");
        print_list(&lmerge);
        break;

    default:
        break;
    }

    destroy(&l1);
    destroy(&l2);
    destroy(&lmerge);
    free(s1->arr);
    free(s1);
    free(s2->arr);
    free(s2);

    return 0;
}