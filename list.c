#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct s_list_node
{
    void *data;
    struct s_list_node *next;
} list_node_t;

list_node_t* list_node_create(void *data, list_node_t *next)
{
    list_node_t *new_list_node = malloc(sizeof(list_node_t));

    new_list_node->data = data;
    new_list_node->next = next;

    return new_list_node;
}

// -----------------------------------------------------------------

typedef struct s_list
{
    size_t size;
    struct s_list_node *head;
} list_t;

list_t* list_create(void)
{
    list_t *new_list = malloc(sizeof(list_t));

    new_list->head = NULL;
    new_list->size = 0;

    return new_list;
}

void list_delete(list_t *list)
{
    list_clear(list);
    free(list);
}

void list_clear(list_t *list)
{
    while (list->size != 0) {
        list_pop_front(list);
    }
}

void list_remove_at(list_t *list, const size_t index)
{
    list_node_t *curr_node = list->head;
    list_node_t *prev_node = list->head;
    size_t curr_node_index = 0;

    while (curr_node != NULL) {
        if (curr_node_index == index) {
            prev_node->next = curr_node->next;
            free(curr_node);
            list->size--;
            return;
        }
        curr_node = curr_node->next;
        prev_node = prev_node->next;
        curr_node_index++;
    }
}

void list_push_back(list_t *list, void *data)
{
    if (list->head == NULL) {
        list->head = list_node_create(data, NULL);
    }
    else {
        list_node_t *new_node = list->head;
        while (new_node->next != NULL) {
            new_node = new_node->next;
        }
        new_node->next = list_node_create(data, NULL);
    }
    list->size++;
}

void list_push_front(list_t *list, void *data)
{
    list_node_t *new_head = list_node_create(data, list->head);
    list->head = new_head;
    list->size++;
}

void list_pop_back(list_t *list)
{
    if (list->head == NULL) {
        return;
    }
    list_node_t *new_node = list->head;
    while (new_node->next != NULL) {
        new_node = new_node->next;
    }
    free(new_node);
    list->size--;
}

void list_pop_front(list_t *list)
{
    list_node_t *node_for_delete = list->head;
    list->head = list->head->next;
    free(node_for_delete);
    list->size--;
}

void* list_at(list_t *list, const size_t index)
{
    list_node_t *curr_node = list->head;
    size_t curr_node_index = 0;

    while (curr_node != NULL) {
        if (curr_node_index == index) {
            return curr_node->data;
        }
        curr_node = curr_node->next;
        curr_node_index++;
    }
}

inline size_t list_size(const list_t *list)
{
    return list->size;
}

inline uint8_t list_is_empty(const list_t *list)
{
    return list->size == 0;
}

void list_print(list_t *list)
{
    list_node_t *node = list->head;
    while (node->next != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

int main()
{
    list_t *list = list_create();

    list_push_back(list, 10);
    list_push_back(list, 20);
    list_push_back(list, 30);
    //list_print(list);
    list_remove_at(list, 1);
    //list_print(list);

    list_delete(list);
    return 0;
}
