#include <stdio.h>
#include <stdlib.h>

// struct node_t;
typedef struct
{
	char *arr;
	int size;
	int capacity;
} word_s;

typedef struct node_t
{
	struct word_s *word;
	struct node_t *prev;
	struct node_t *next;
} node_t;

typedef struct
{
	node_t *head;
	size_t size;
} list_t;

void init(list_t *l)
{
	l->head = NULL;
	l->size = 0;
}

void destroy(list_t *l)
{
	node_t *cur = l->head;
	word_s *word = NULL;
	node_t *prev = NULL;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		word = prev->word;
		free(word->arr);
		free(word);
		free(prev);
	}
}

void push_back(list_t *l, char *ws, size_t sizews, int capws)
{
	node_t *n, *cur;
	word_s *w_t;
	n = (node_t *)malloc(sizeof(node_t));
	w_t = (word_s *)malloc(sizeof(word_s));

	w_t->arr = ws;
	w_t->size = sizews;
	w_t->capacity = capws;
	n->word = w_t;
	n->next = NULL;
	if (l->head == NULL)
	{
		n->prev = NULL;
		l->head = n;
	}
	else
	{
		cur = l->head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = n;
		n->prev = cur;
	}
	l->size++;
}

void readstr(char *tmp, size_t size, list_t *list)
{
	int len = 0;
	int capacity = 1;						// емкость динамической строки
	char *s = (char *)malloc(sizeof(char)); // динамическая пустая строка
	for (size_t i = 0; i < size; i++)
	{
		// printf("%c",tmp[i]);
		if (is_char(tmp[i]) == 1)
		{
			s[(len)++] = tmp[i];
			if (len >= capacity)
			{													 // если реальный размер больше размера контейнера, то увеличим его размер
				capacity *= 2;									 // увеличиваем емкость в два раза
				s = (char *)realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной емкостью
			}
			if (i + 1 == size)
				goto last_char;
		}
		else
		{
			last_char:
			if (len != 0)
			{
				printf("%d\n", len);
				s[len] = '\0';
				
				push_back(list, s, len, capacity);
				printf("----1---\n\n");
				len = 0;
				capacity = 1;						// емкость динамической строки
				// char *s = NULL;
				s = (char *)malloc(sizeof(char)); // динамическая пустая строка
				// s[0]='d';
				// printf("%s",s);
				
			}
		}
	}
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