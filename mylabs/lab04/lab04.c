#include <stdio.h>

void sort_int(int *mass, int size, int revert)
{
    if (revert == 1)
    {
        for (int j = 0; j < size; j++)
        {
            for (int i = (size - 1); i > j; i--)
            {
                if (mass[i - 1] < mass[i])
                {
                    int temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
    }
    else
        for (int j = 0; j < size; j++)
        {
            for (int i = (size - 1); i > j; i--)
            {
                if (mass[i - 1] > mass[i])
                {
                    int temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
}

void sort_str(char **mass, int size, int word_size, int revert)
{
    if (revert == 1)
    {
        for (int j = 0; j < size; j++)
        {

            for (int i = (size - 1); i > j; i--)
            {   
                int pr_s = strlen(mass[i - 1], word_size);
                int ns_s = strlen(mass[i], word_size);
                
                if (pr_s < ns_s)
                {
                    char *temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
    }
    else
        for (int j = 0; j < size; j++)
        {
            for (int i = (size - 1); i > j; i--)
            {
                int pr_s = strlen(mass[i - 1], word_size);
                int ns_s = strlen(mass[i], word_size);
                
                if (pr_s > ns_s)
                {
                    char *temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
}

int main(int argc, char const *argv[])
{
    int size = 300;
    char str[300] = {0};
    fgets(str, size+1, stdin);
    fflush(stdin);
    

    // wordsl[x][y]
    // x - words count
    // y - max word length
    // 15 - words
    // 20 - max length
    char wordsl[15][20]={0};
    int word_size = 20;
    int word_count = 15;

    int selected_word=0;
    int selected_char=0;
    int prev_state = 0;

    for (int v=0; v<size; v++){
        if (str[v]!='\0' && str[v]!='\n'){
            int st_char = is_char(str[v]);

            if (prev_state==1 && st_char==0){
                selected_word +=1;
                selected_char = 0;
            }
            if (st_char==1){
                wordsl[selected_word][selected_char] = str[v];
                selected_char++;
            }


            prev_state = st_char;
        }
            
    }
    
    sort_str(wordsl, word_count, word_size,0);
    for(int i=0;i<word_count;i++){
        if (is_not_free(wordsl[i], word_size)==1)

            
            printf("%s  ", wordsl[i]);
    }
    return 0;
}

int strlen(char *str, int dlinna)
{
    for (int i = 0; i < dlinna; i++)
    {
        if (str[i] == '\0' || str[i] == '\n')
            return i;
    }
    return dlinna;
}

int is_not_free(char* mass, int dlina){
    for(int x=0; x<dlina;x++){
        if (mass[x]!='\0')
            return 1;
    }
    return 0;
}

int is_char(int ch){
    if ( 
        (65<=ch&&ch<=90) || (97<=ch&&ch<=122)
        ||
        (128<=ch&&ch<=175) || (224<=ch&&ch<=239)
    )
        return 1;
    else
        return 0;

}