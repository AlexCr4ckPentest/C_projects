#include "../include/list.h"
#include <stdlib.h>

static void assert_throw_error(int expr, const char *e_msg, int e_code)
{
    if (!expr) {
        fprintf(stderr, "%s", e_msg);
        exit(e_code);
    }
}

typedef struct s_list_node
{
    void *data;
    struct s_list_node *next;
} list_node_t;

typedef struct s_list
{
    size_t size;
    struct s_list_node *head;
    struct s_list_node *last;
    struct s_list_node *first;
} list_t;

list_node_t* list_node_create(void *data, list_node_t *next)
{
    list_node_t *new_list_node = malloc(sizeof(list_node_t));
    new_list_node->data = data;
    new_list_node->next = next;
    return new_list_node;
}

list_t* list_create(void)
{
    list_t *new_list = malloc(sizeof(list_t));

    new_list->size = 0;
    new_list->head = NULL;
    new_list->last = NULL;
    new_list->first = NULL;

    return new_list;
}

void list_delete(list_t *list)
{
    list_clear(list);
    free(list);
    list = NULL;
}

void list_clear(list_t *list)
{
    while (list->size != 0) {
        list_pop_front(list);
    }
}

void list_push_back(list_t *list, void *data)
{
    if (list->head == NULL) {
        list->head = list_node_create(data, NULL);
        list->last = list->head;
    }
    else {
        list_node_t *last_node = list->head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = list_node_create(data, NULL);
        list->last = last_node->next;
    }
    list->size++;
}

void list_push_front(list_t *list, void *data)
{
    list->head = list_node_create(data, list->head);
    list->first = list->head;
    list->size++;
}

void list_pop_back(list_t *list)
{
    assert_throw_error(list->size != 0, "list_pop_back(): assertation failed: list size is 0!\n", 1);

    list_node_t *node_for_delete = list->head;
    while (node_for_delete->next != NULL) {
        list->last = node_for_delete;
        node_for_delete = node_for_delete->next;
    }
    free(node_for_delete);
    list->size--;
}

void list_pop_front(list_t *list)
{
    assert_throw_error(list->size != 0, "list_pop_front(): assertation failed: list size is 0!\n", 1);

    list_node_t *node_for_delete = list->head;
    list->head = list->head->next;
    list->first = list->head;
    free(node_for_delete);
    list->size--;
}

void list_remove_at(list_t *list, const size_t index)
{
    assert_throw_error(list->size != 0, "list_remove_at(): assertation failed: list size is 0!\n", 1);
    assert_throw_error(index < list->size, "list_remove_at(): assertation failed: index out of range!\n", 2);

    if (index == 0) {
        list_pop_front(list);
    }
    else {
        list_node_t *prev_node = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev_node = prev_node->next;
        }
        list_node_t *node_for_delete = prev_node->next;
        prev_node->next = node_for_delete->next;
        free(node_for_delete);
        list->size--;
    }
}

void list_insert(list_t *list, void *data, const size_t index)
{
    assert_throw_error(index < list->size, "list_insert(): assertation failed: index out of range!\n", 2);

    if (index == 0) {
        list_push_front(list, data);
    }
    else {
        list_node_t *prev_node = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev_node = prev_node->next;
        }
        prev_node->next = list_node_create(data, prev_node->next);
        list->size++;
    }
}

void* list_at(list_t *list, const size_t index)
{
    assert_throw_error(list->size != 0, "list_at(): assertation failed: list size is 0!\n", 1);
    assert_throw_error(index < list->size, "list_at(): assertation failed: index out of range!\n", 2);

    size_t curr_node_index = 0;
    list_node_t *curr_node = list->head;
    while (curr_node != NULL) {
        if (index == curr_node_index) {
            return curr_node->data;
        }
        curr_node = curr_node->next;
        curr_node_index++;
    }
}

inline void* list_last(list_t *list)
{
    return list->last->data;
}

inline void* list_first(list_t *list)
{
    return list->first->data;
}

inline size_t list_size(const list_t *list)
{
    return list->size;
}

inline uint8_t list_is_empty(const list_t *list)
{
    return list->size == 0;
}

void list_print(list_t *list, const char *format, FILE *out)
{
    assert_throw_error(list->head != NULL, "list_print(): assertation failed: list size is 0!\n", 1);

    list_node_t *node = list->head;
    while (node != NULL) {
        fprintf(out, format, node->data);
        node = node->next;
    }
}

void list_reverse(list_t *list)
{
    assert_throw_error(list->size != 0, "list_reverse(): assertation failed: list size is 0!\n", 1);

    list_node_t *prev = NULL;
    list_node_t *curr = list->head;
    list_node_t *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}
