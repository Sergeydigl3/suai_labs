// Написать функцию void pathsplit(char *path, char *split[]) для расщепления полного пути к файлу на диск, директории, имя 
// и расширение, которые разместить в динамической памяти (malloc), а указатели на них поместить в массив указателей.
#include "lab11.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

int main() {
    char t_path[] = "C:\\codePack\\moodle-answers-script\\README.md";
    char drvie_preffix[] = ":\\";

    char* pch = strtok(t_path, drvie_preffix);
    char* str;
    while (pch != NULL)
    {
        printf("\n%s %ld", pch, strlen(pch));
        size_t t_size = strlen(pch) + 1;
        str = (char*)malloc(sizeof(char) * t_size);
        for (size_t i = 0; i < t_size; i++)
            str[i] = pch[i];

        char* t_char = pch;


        pch = strtok(NULL, drvie_preffix);
        if(pch == NULL){
            for (int i = t_size; i > -1; i++)
            {
                if (str[i]=='.')
            }
            
        }
    }
    printf("\n");
    // pathsplit(t_path,);
}