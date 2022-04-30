#include <string.h>
#include <stdio.h>
#include <malloc.h>

void pathsplit(char* t_path, char* massive[]) {
    char drvie_preffix[] = ":\\";

    char* pch = strtok(t_path, drvie_preffix);
    char* str;
    int mass_counter = 1;
    

    while (pch != NULL)
    {
        // printf("\n%s %ld", pch, strlen(pch));
        size_t t_size = strlen(pch) + 1;
        str = (char*)malloc(sizeof(char) * t_size);
        mass_counter++; massive = (char**)realloc(massive, sizeof(char*) * mass_counter);

        for (size_t i = 0; i < t_size; i++)
            str[i] = pch[i];
        massive[mass_counter - 2] = str;
        char* t_char = pch;

        pch = strtok(NULL, drvie_preffix);
        if (pch == NULL) {

            unsigned int ext_size = 1;
            char* extintion = (char*)calloc(ext_size, sizeof(char));

            int extintion_start = -1;
            for (int i = t_size; i > 0; i--)
            {
                if (str[i] == '.') { extintion_start = i; break; }
            }
            if (extintion_start == -1) extintion_start = t_size;
            char* filename = (char*)calloc(extintion_start, sizeof(char));

            for (size_t i = 0; i < extintion_start; i++)
            {
                filename[i] = str[i];
            }
            // mass_counter++; massive = (char **) realloc(massive, sizeof(char*)*mass_counter);
            // massive[mass_counter-1] = filename;
            for (size_t i = extintion_start + 1; i < t_size; i++)
            {
                extintion[i - extintion_start - 1] = str[i];
            }
            free(massive[mass_counter - 2]);
            massive[mass_counter - 2] = filename;
            massive[mass_counter - 1] = extintion;

            // printf("%s\n", filename);
            // printf("%s\n", filenam);


        }
    }

    printf("\n");
    for (size_t i = 0; i < mass_counter; i++)
    {
        printf("%s\n", massive[i]);
    }
    printf("\n\n%s\n", massive[0]);
}