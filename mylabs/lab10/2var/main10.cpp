// Подсчитать частоту использования каждой операции языка С в символьном файле с программой на С.
#include <stdio.h>
#include <iostream>
#include "lab10.h"
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;


int main() {
    file_s* s1 = read_file("demo.c");

    char actions[][STR_SIZE] = { "==", "!=", "<=", ">=", "++", "--", "&&", "||", "<<", ">>", "!", ">", "<", "`", "&", "|", "^", "=", "*", "/", "%", "-", "+", };

    size_t act_count = sizeof(actions) / STR_SIZE;

    oper_s** oper_mass = (oper_s**)malloc(sizeof(oper_s) * act_count);
    for (size_t i = 0; i < act_count; i++)
    {
        oper_mass[i] = new oper_s;
        oper_mass[i]->count = 0;
        oper_mass[i]->op = (char*)calloc(STR_SIZE, sizeof(char));
        for (size_t d = 0; d < STR_SIZE; d++) oper_mass[i]->op[d] = actions[i][d];
        oper_mass[i]->size = strlen(oper_mass[i]->op);
    }

    int bad_str = 0;
    for (size_t i = 0; i < s1->size - (STR_SIZE - 2); i++)
    {
        
        for (size_t j = 0; j < act_count; j++)
        {   
            if (s1->arr[i]=='#') bad_str=1;
            else if (s1->arr[i]=='\n') bad_str=0;
            if (bad_str) continue;
            
            int similar = 1;
            for (size_t k = 0; k < oper_mass[j]->size; k++)
            {
                if (s1->arr[i + k] != oper_mass[j]->op[k]) { similar = 0; break; }
            }
            if (similar == 1) { oper_mass[j]->count++; i += oper_mass[j]->size - 1; break; };
        }

    }

    for (size_t j = 0; j < act_count; j++)
    {
        cout << endl << "Operator: " << oper_mass[j]->op << " || Count:" << oper_mass[j]->count << endl;
    }



}