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
    int mass_counter = -1;
    char **massive = (char **) malloc(sizeof(char*)*mass_counter);
    
    while (pch != NULL)
    {
        printf("\n%s %ld", pch, strlen(pch));
        size_t t_size = strlen(pch) + 1;
        str = (char*)malloc(sizeof(char) * t_size);
        mass_counter++; massive = (char **) realloc(massive, sizeof(char*)*mass_counter);
        
        for (size_t i = 0; i < t_size; i++)
            str[i] = pch[i];
        massive[mass_counter] = str;
        char* t_char = pch;

        pch = strtok(NULL, drvie_preffix);
        if (pch == NULL) {
            char* new_ext = (char*)malloc(sizeof(char) * t_size);
            size_t t_count = 0;
            int flag = 0;


            for (int i = 0; i < t_size; i++)
            {
                if (flag == 1) {
                    new_ext[t_count] = t_char[i];
                    t_count++;
                }
                if (str[i] == '.') flag = 1;
                if (flag == 1) t_char[i] = 0; 
            }
            new_ext[t_count] = 0;
            
            // printf("\n%s %ld", pch, strlen(pch));
            printf("\n%s %ld", new_ext, strlen(new_ext));


        }
    }
    printf("\n");
    // pathsplit(t_path,);
}