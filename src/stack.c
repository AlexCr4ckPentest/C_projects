#include "../include/stack.h"
#include <stdlib.h>
#include <assert.h>

stack_t* stack_create(void)
{
    stack_t *new_stack = list_create();
    return new_stack;
}

inline void stack_delete(stack_t *stack)
{
    list_delete(stack);
}

inline void stack_push(stack_t *stack, void *data)
{
    list_push_front(stack, data);
}

inline void stack_pop(stack_t *stack)
{
    list_pop_front(list);
}

inline void* stack_top(stack_t *stack)
{
    return stack->head->data;
}
