#include <stdio.h>
#define WORDSL_X 15 // Word count
#define WORDSL_Y 20 // Max length

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

void sort_str_length(char (*mass)[WORDSL_Y], int size, int word_size, int revert)
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

                    int f1 = i;
                    int f2 = i - 1;
                    char temp[WORDSL_Y] = {0};
                    //copying f2
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        temp[i] = mass[f2][i];
                    }

                    //rewrite f2 form f1
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f2][i] = mass[f1][i];
                    }

                    //rewrite f1 from temp
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f1][i] = temp[i];
                    }

                    // mass_exchange(mass, i, i - 1);

                    // char temp[WORDSL_Y] = mass[i - 1];
                    // mass[i - 1] = mass[i];
                    // mass[i] = temp;
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
                    int f1 = i;
                    int f2 = i - 1;
                    char temp[WORDSL_Y] = {0};
                    //copying f2
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        temp[i] = mass[f2][i];
                    }

                    //rewrite f2 form f1
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f2][i] = mass[f1][i];
                    }

                    //rewrite f1 from temp
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f1][i] = temp[i];
                    }

                    // mass_exchange(mass, i, i-1);
                    // char temp[WORDSL_Y] = mass[i - 1];
                    // mass[i - 1] = mass[i];
                    // mass[i] = temp;
                }
            }
        }
}

void sort_str_alph(char (*mass)[WORDSL_Y], int size, int word_size, int revert)
{
    if (revert == 0)
    {
        for (int j = 0; j < size; j++)
        {

            for (int i = (size - 1); i > j; i--)
            {

                // int pr_s = strlen(mass[i - 1], word_size);
                // int ns_s = strlen(mass[i], word_size);

                if (check_alphabet(mass[i], mass[i-1], word_size,0))
                {

                    int f1 = i;
                    int f2 = i - 1;
                    char temp[WORDSL_Y] = {0};
                    //copying f2
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        temp[i] = mass[f2][i];
                    }

                    //rewrite f2 form f1
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f2][i] = mass[f1][i];
                    }

                    //rewrite f1 from temp
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f1][i] = temp[i];
                    }

                    // mass_exchange(mass, i, i - 1);

                    // char temp[WORDSL_Y] = mass[i - 1];
                    // mass[i - 1] = mass[i];
                    // mass[i] = temp;
                }
            }
        }
    }
    else
        for (int j = 0; j < size; j++)
        {
            for (int i = (size - 1); i > j; i--)
            {
                // int pr_s = strlen(mass[i - 1], word_size);
                // int ns_s = strlen(mass[i], word_size);

                if (check_alphabet(mass[i], mass[i-1], word_size,1))
                {
                    int f1 = i;
                    int f2 = i - 1;
                    char temp[WORDSL_Y] = {0};
                    //copying f2
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        temp[i] = mass[f2][i];
                    }

                    //rewrite f2 form f1
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f2][i] = mass[f1][i];
                    }

                    //rewrite f1 from temp
                    for (int i = 0; i < WORDSL_Y; i++)
                    {
                        mass[f1][i] = temp[i];
                    }

                    // mass_exchange(mass, i, i-1);
                    // char temp[WORDSL_Y] = mass[i - 1];
                    // mass[i - 1] = mass[i];
                    // mass[i] = temp;
                }
            }
        }
}

int strlen(char *str, int dlinna)
{
    // print_array(str, dlinna);
    for (int i = 0; i < dlinna; i++)
    {
        if (str[i] == '\0' || str[i] == '\n')
            return i;
    }
    return dlinna;
}

int print_array(int x[], int len)
{
    int k;

    for (k = 0; k < len; k++)
    {
        printf("x[%d] = %d\n", k, x[k]);
    }
    return 0;
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

int check_alphabet(char *w1, char *w2, int size, int reverse)
{
    //From m1 higher m2
    if (reverse == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (w1[i]<w2[i])
                return 1;

        }
        return 0;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (w1[i]>w2[i])
                return 1;
        }
        return 0;
    }

    // TODO: сортировка по алфавиту
}

int main(int argc, char const *argv[])
{
    int size = WORDSL_Y * WORDSL_X;
    char str[WORDSL_Y * WORDSL_X] = {0};
    fgets(str, size + 1, stdin);
    fflush(stdin);

    // wordsl[x][y]
    // x - words count
    // y - max word length
    // 15 - words
    // 20 - max length
    char wordsl[WORDSL_X][WORDSL_Y] = {0};

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

    // sort_str(wordsl, WORDSL_X, WORDSL_Y, 0);
    sort_str_alph(wordsl, WORDSL_X, WORDSL_Y, 0);

    for (int i = 0; i < WORDSL_X; i++)
    {
        if (is_not_free(wordsl[i], WORDSL_Y) == 1)

            printf("%s ", wordsl[i]);
    }
    return 0;
}
