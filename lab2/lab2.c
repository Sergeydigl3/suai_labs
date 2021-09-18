#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size = 300;
    char str[300] = {0};
    int size_obr = 100;
    char obr[100] = {0};

    int otvets[10] = {0};

    printf("Строка: ");
    fgets(str, size + 1, stdin);
    fflush(stdin);
    // TODO: Make Len Size for  (for cycle)
    printf("Образец поиска: ");
    fgets(obr, size_obr + 1, stdin);
    fflush(stdin);

    int obr_pos = 0;
    for (int i = 0; i < size; i++)
    {
        if (
            (is_char(str[i])==1) && (is_char(obr[i])==1) && (str[i] == obr[obr_pos]))
        {
            obr_pos++;
        }
        
        if (str[i] != obr[obr_pos]){
            obr_pos = 0;
            printf("Позиция %d", i);
        }
    }
}

int is_not_free(char *mass, int dlina)
{
    for (int x = 0; x < dlina; x++)
    {
        if (mass[x] != '\0')
            return 1;
    }
    return 0;
}

int is_char(int ch)
{
    if (
        (65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
        (128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
        return 1;
    else
        return 0;
}
