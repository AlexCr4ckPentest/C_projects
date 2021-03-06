#include <stdio.h>
#include <stdbool.h>

#ifndef _LIST_H_
#define _LIST_H_

typedef struct s_list_node list_node_t;
typedef struct s_list list_t;

list_node_t* list_node_create(void *data, list_node_t *next);

list_t* list_create(void);

void list_delete(list_t *list);
void list_clear(list_t *list);

void list_push_back(list_t *list, void *data);
void list_push_front(list_t *list, void *data);

void list_pop_back(list_t *list);
void list_pop_front(list_t *list);
void list_remove_at(list_t *list, const size_t index);

void list_insert(list_t *list, void *data, const size_t index);

void* list_at(list_t *list, const size_t index);
extern void* list_last(list_t *list);
extern void* list_first(list_t *list);

extern size_t list_size(const list_t *list);

extern bool list_is_empty(const list_t *list);

void list_print(list_t *list, const char *format, FILE *out);

void list_reverse(list_t *list);

#endif // _LIST_H_
