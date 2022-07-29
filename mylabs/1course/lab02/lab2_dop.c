#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size = 300;
    char str[300] = {0};
    printf("Str: ");
    fgets(str, size + 1, stdin);
    fflush(stdin);

    int repeat_in;
    printf("Repeats >= ");
    scanf_s("%d", &repeat_in);

    // wordsl[x][y]
    // x - words count
    // y - max word length
    // 15 - words
    // 20 - max length
    char wordsl[15][20] = {0};
    char wordsl_repeat_del[15][20] = {0};
    int repeat[15] = {0};

    int selected_word = 0;
    int selected_char = 0;
    int prev_state = 0;

    for (int v = 0; v < size; v++)
    {
        if (str[v] != '\0' && str[v] != '\n')
        {
            int st_char = is_char(str[v]);

            if (prev_state == 1 && st_char == 0)
            {
                selected_word += 1;
                selected_char = 0;
            }
            if (st_char == 1)
            {
                wordsl[selected_word][selected_char] = str[v];
                selected_char++;
            }

            prev_state = st_char;
        }
    }

    int counter_new = 0;

    for (int i = 0; i < 15; i++)
    {
        //check in new massive
        // 1 - Ok
        // 0 - Bad
        int state = 1;
        for (int x = 0; x < 15; x++)
        {
            if (is_not_free(wordsl[x], 20) == 0)
            {
                // printf("Huita");
                break;
            }
            else
            {
                if (check_example(wordsl_repeat_del[x], wordsl[i], strlen(wordsl[i], 20), 0) == 1)
                    state = 0;
            }
        }

        if (state == 1)
        {
            for (int x = 0; x < 20; x++)
            {
                wordsl_repeat_del[counter_new][x] = wordsl[i][x];
            }
            counter_new++;
        }
    }

    for (int i = 0; i < counter_new; i++)
    {
        for (int x = 0; x < 15; x++)
            if (check_example(wordsl[x], wordsl_repeat_del[i], 20, 0) == 1)
                repeat[i]++;
    }

    for (int i = 0; i < counter_new; i++){
        if (repeat[i]>=repeat_in){
            printf("%s %d\n", wordsl_repeat_del[i], repeat[i]);
        }
    }



    return 0;
}

// 1 - Similar
// 0 - Not similar
int check_example(char *str, char *obr, int size_obr, int st_pos)
{
    for (int i = 0; i < size_obr; i++)
    {
        if (str[st_pos + i] != obr[i])
        {
            return 0;
        }
    }
    return 1;
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

int is_not_free(char *mass, int dlina)
{
    for (int x = 0; x < dlina; x++)
    {
        if (mass[x] != '\0')
            return 1;
    }
    return 0;
}

int is_char(int ch)
{
    if (
        (65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
        (128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
        return 1;
    else
        return 0;
}