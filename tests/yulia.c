///Написать программу составления двоичного дерева слов по символьному файлу и функцию определения глубины дерева
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    char *word; // поле данных
    int capacity;
    int count;
    struct tnode *left;  // левый потомок
    struct tnode *right; // правый потомок
    struct tnode *root;  // рут

} tnode;

typedef struct tree
{
    tnode *head; // ссылка на корень
    int count;   // количество элементов
} tree;

typedef struct file
{
    char *str;
    int size;
} file;

size_t file_size(FILE *file)
{
    fseek(file, 0, SEEK_END);
    size_t fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    return fsize;
}

file *read_file(char *path)
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
        perror("Error opening file");
    // read string from file
    size_t fsize = file_size(f);
    char *str = (char *)malloc(fsize * sizeof(char));
    for (size_t i = 0; i < fsize; i++)
        str[i] = fgetc(f);
    fclose(f);
    // create file structure
    file *temp_file = (file *)malloc(sizeof(file));
    temp_file->str = str;
    temp_file->size = fsize;
    return temp_file;
}

int strcmp(char *s1, char *s2)
{
    char c1, c2;
    while ((c1 = *s1++) == (c2 = *s2++))
        if (c1 == '\0')
            return 0;
    return c1 - c2;
}

int is_char(int ch)
{
    return (int)((97 <= ch && ch <= 122) ||
                 (128 <= ch && ch <= 175) ||
                 (224 <= ch && ch <= 239) ||
                 (65 <= ch && ch <= 90));
}

void addTree(tree *t, char *str, int capacity)
{
    struct tnode *temp_node = (tnode *)malloc(sizeof(tnode));
    temp_node->word = str;
    temp_node->capacity = capacity;
    temp_node->right = NULL;
    temp_node->left = NULL;
    temp_node->root = NULL;
    temp_node->count = 1;
    if (t->head == NULL)
    {
        t->head = temp_node;
        // temp_node->count = 1;
    }
    else
    {
        struct tnode *source = t->head;
        int flag = 0;
        do
        {
            if (strcmp(str, source->word) > 0)
                if (source->right != NULL)
                    source = source->right;
                else
                    flag = -1;
            else if (strcmp(str, source->word) < 0)
                if (source->left != NULL)
                    source = source->left;
                else
                    flag = 1;
            else
            {
                source->count++;
                free(temp_node);
                break;
            }
        } while (flag == 0);
        if (flag == -1)
            source->right = temp_node;
        else if (flag == 1)
            source->left = temp_node;
    }
    t->count++;
}

// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!
void parse_str(char *temp, size_t size, tree *t)
{
    int capacity = 1, len = 0;
    char *str = (char *)malloc(sizeof(char));
    for (size_t i = 0; i < size; i++)
    {
        if (is_char(temp[i]))
        {
            str[len++] = temp[i];
            if (len >= capacity)
                str = (char *)realloc(str, (capacity *= 2) * sizeof(char));
            if (size - i == 1)
                goto word_end;
        }
        else
        {
        word_end:
            if (len)
            {
                str[len] = '\0';
                addTree(t, str, capacity);
                capacity = 1;
                len = 0;
                str = (char *)malloc(sizeof(char));
            }
        }
    }
}

void init(struct tree *t)
{
    t->head = NULL;
    t->count = 0;
}

// пиши тут
// yulya.work();
// denis.tea();

void printTree(struct tnode *node)
{
    printf("%d %s\n", node->count, node->word);
    if (node->left != NULL)
        printTree(node->left);
    if (node->right != NULL)
        printTree(node->right);
}

int DeepTree(tnode* tree) {
    int deepR = 0;
    int deepL= 0;
    if (tree == NULL) {
        printf("error in the memory");
        return 0;
    }
    if (tree->left != NULL) {
        deepL = DeepTree(tree->left);
        deepL++;
    }
    if (tree->right != NULL) {
        deepR = DeepTree(tree->right);
        deepR++;
    }
    if (deepR > deepL) {
        return deepR;
    }
    else {
        return deepL;
    }  
}

int main()
{
    file *f = read_file("C:/src/codePack/suai_labs/tests/file.txt");
    tree my_tree;
    init(&my_tree);
    parse_str(f->str, f->size, &my_tree);
    printf("Deep tree: %d\n", DeepTree((&my_tree)->head));
    printTree((&my_tree)->head);
}