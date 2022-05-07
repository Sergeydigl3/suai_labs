#include <string.h>
#include <stdio.h>
#include <malloc.h>

// TODO: Доп 1Есть текстовый файл с абсолютными путями. Сделать группировку по типам рассширений (Заранее указаны)

void pathsplit(char* t_path, char** massive[]) {
    char drvie_preffix[] = ":\\";
    
    int mass_counter = 1;
    *massive = (char**)malloc(sizeof(char*) * mass_counter); (*massive)[mass_counter-1] = NULL;

    char* pch = strtok(t_path, drvie_preffix);
    char* str;
    

    while (pch != NULL)
    {
        size_t t_size = strlen(pch) + 1;
        str = (char*)malloc(sizeof(char) * t_size);
        mass_counter++; *massive = (char**)realloc(*massive, sizeof(char*) * mass_counter); (*massive)[mass_counter-1] = NULL;

        for (size_t i = 0; i < t_size; i++)
            str[i] = pch[i];
        (*massive)[mass_counter - 2] = str;
        char* t_char = pch;

        pch = strtok(NULL, drvie_preffix);
        if (pch == NULL) {
            unsigned int ext_size = 1; // выделяем массив и считаем кол-во символов расширения
            char* extintion = (char*)calloc(ext_size, sizeof(char));

            int extintion_start = -1;
            for (int i = t_size; i > 0; i--)
            {
                if (str[i] == '.') { extintion_start = i; break; }
            }
            if (extintion_start == -1) continue; // если это директория - выходим

            mass_counter++; *massive = (char**)realloc(*massive, sizeof(char*) * mass_counter); (*massive)[mass_counter-1] = NULL; // берём слот под расширение дополнительно

            char* filename = (char*)calloc(extintion_start, sizeof(char));


            for (size_t i = 0; i < extintion_start; i++)
            {
                filename[i] = str[i];
            }
            for (size_t i = extintion_start + 1; i < t_size; i++)
            {
                extintion[i - extintion_start - 1] = str[i];
            }
            
            free((*massive)[mass_counter - 3]);
            (*massive)[mass_counter - 3] = filename;
            (*massive)[mass_counter - 2] = extintion;
        }
    }
}

void printMassive(char **massive){
    if (massive == NULL){
        perror("in pathsplit() memory allocation error");
    }
    while(*massive!=NULL) {
        printf("%s\n", *(massive++));
    }
}