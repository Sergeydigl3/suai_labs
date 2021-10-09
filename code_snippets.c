#include <stdio.h>
#include <stdlib.h>

// struct node_t;
typedef struct
{
	char *arr;
	int size;
}word_s;

typedef struct node_t
{
	struct word_s *word;
	struct node_t *prev;
	struct node_t *next;
}node_t;

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
	word_s *word;
	node_t *prev = NULL;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		word = prev->word;
		free(word->arr);
		free(prev);
	}
}

void push_back(list_t *l, char * ws, size_t sizews)
{
	node_t *n, *cur;
	word_s *w_t;
	n = (node_t *)malloc(sizeof(node_t));
	w_t->arr = ws;
	w_t->size = sizews;
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