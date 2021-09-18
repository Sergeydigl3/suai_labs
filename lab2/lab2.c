#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size = 300;
    char str[300] = {0};
    int size_obr = 100;
    char obr[100] = {0};

    int otvets[10] = {0};

    printf("Stroka: ");
    fgets(str, size + 1, stdin);
    fflush(stdin);
    size = strlen(str, size);

    printf("Obr search: ");
    fgets(obr, size_obr + 1, stdin);
    fflush(stdin);
    size_obr = strlen(obr, size_obr);

    printf("Similar: %d", check_example(str, obr, size_obr, 0));
    // for (int i = 0; i < size; i++)
    // {   
        
    //     // check_example();
    // }
}

// 1 - Similar
// 0 - Not similar
int check_example(char *str, char *obr, int size_obr, int st_pos){
    for (int i=0;i<size_obr;i++){
        if (
            str[st_pos+i] != obr[i]
            ){
            return 0;
        }
    }
    return 1;
}

int strlen(char *str, int dlinna){
    for (int i=0;i<dlinna;i++){
        if (str[i]=='\0' || str[i]=='\n')
            return i;
    }
    return dlinna;
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
