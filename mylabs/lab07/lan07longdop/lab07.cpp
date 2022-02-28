#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double str_to_double(char *str){
        int str_count = strlen(str);
        char * temp = (char *)calloc(str_count, sizeof(char));
        int temp_count = 0;
        double result = 0;
        for (size_t i = 0; i < str_count; i++)
        {
            if(str[i] == '.'){
                result = (double) atoi(temp);
                free(temp);
                temp = (char *)calloc(str_count, sizeof(char));
                temp_count=0;
            } else {
                temp[temp_count] = str[i];
                temp_count++; 
            }
        }
        result = result>0 ? result+((double)atoi(temp))*pow((0.1), (double)temp_count) : result-((double)atoi(temp))*pow((0.1), (double)temp_count);
        free(temp);
        return result;
}

