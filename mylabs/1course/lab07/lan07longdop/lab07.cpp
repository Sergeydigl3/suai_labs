#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// double str_to_double(char *str){
//         int str_count = strlen(str);
//         char * temp = (char *)calloc(str_count, sizeof(char));
//         int temp_count = 0;
//         double result = 0;
//         for (size_t i = 0; i < str_count; i++)
//         {
//             if(str[i] == '.'){
//                 result = (double) atoi(temp);
//                 free(temp);
//                 temp = (char *)calloc(str_count, sizeof(char));
//                 temp_count=0;
//             } else {
//                 temp[temp_count] = str[i];
//                 temp_count++;
//             }
//         }
//         result = result>0 ? result+((double)atoi(temp))*pow((0.1), (double)temp_count) : result-((double)atoi(temp))*pow((0.1), (double)temp_count);
//         free(temp);
//         return result;
// }

int stupid_check(char *str, size_t size, double dd)
{
    for (size_t i = 0; i < size; i++)
    {
        // printf("%s\n",str);
        // if (size>=3&&(str[i] == 'n' || str[i] == 'N')) printf("DA DA");
        if (size>=3&&(str[i] == 'n' || str[i] == 'N')) if (str[i+1] == 'a' || str[i+1] == 'A') if (str[i+2] == 'n' || str[i+2] == 'N') return 1;
        if (size>=4&&(str[i] == '-')) if (str[i+1] == 'i' || str[i+1] == 'I') if (str[i+2] == 'n' || str[i+2] == 'N') if (str[i+3] == 'f' || str[i+3] == 'F') return 2;
        if (size>=3&&(str[i] == 'i' || str[i] == 'I')) if (str[i+1] == 'n' || str[i+1] == 'N') if (str[i+2] == 'f' || str[i+2] == 'F') return 3;
    }   
    return 0;
}

double str_to_double(char *str)
{
    int str_count = strlen(str);
    char *temp = (char *)calloc(str_count, sizeof(char));
    int temp_count = 0;
    double result = 0;
    int tresult = 0;
    for (size_t i = 0; i < str_count; i++)
    {
        if (str[i] == '.')
        {
            result = (double)atoi(temp);
            free(temp);
            temp = (char *)calloc(str_count, sizeof(char));
            temp_count = 0;
        }
        else
        {
            temp[temp_count] = str[i];
            temp_count++;
        }

        tresult = stupid_check(temp, temp_count, result);
        switch (tresult)
        {
        case 1:
            result = NAN;
            break;
        case 2:
            result = -INFINITY;
            break;
        case 3:
            result = INFINITY;
            break;
        default:
            break;
        }
        if (tresult!=0) break;
    }
    if (tresult==0) result = result > 0 ? result + ((double)atoi(temp)) * pow((0.1), (double)temp_count) : result - ((double)atoi(temp)) * pow((0.1), (double)temp_count);
    free(temp);
    return result;
}