// Написать функцию void pathsplit(char *path, char *split[]) для расщепления полного пути к файлу на диск, директории, имя 
// и расширение, которые разместить в динамической памяти (malloc), а указатели на них поместить в массив указателей.
#include "lab11.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

int main() {
    char t_path[] = "C:\\codePack\\moodle-answers-script\\README.d";

    int mass_counter = 1;
    char** massive = (char**)malloc(sizeof(char*) * mass_counter);
    pathsplit(t_path, massive);
    
    printf("\n\n%s\n", massive[0]);
    
    // pathsplit(t_path,);
}