#include "../include/stack.h"

inline stack_t* stack_create(void)
{
    return list_create();
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
    list_pop_front(stack);
}

inline void* stack_top(stack_t *stack)
{
    return list_first(stack);
}

inline void stack_clear(stack_t *stack)
{
    list_clear(stack);
}

inline bool stack_is_empty(stack_t *stack)
{
    return list_is_empty(stack);
}

inline size_t stack_size(stack_t *stack)
{
    return list_size(stack);
}
