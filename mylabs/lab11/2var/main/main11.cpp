// Написать функцию void pathsplit(char *path, char *split[]) для расщепления полного пути к файлу на диск, директории, имя 
// и расширение, которые разместить в динамической памяти (malloc), а указатели на них поместить в массив указателей.
#include "lab11.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

int main() {
    char t_path[] = "C:\\codePack\\moodle-answers-script\\.README\\test.py";

    char** massive = NULL;
    pathsplit(t_path, &massive);
    printMassive(massive);
}