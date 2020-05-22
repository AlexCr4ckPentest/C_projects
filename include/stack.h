#include "list.h"

#ifndef _STACK_H_
#define _STACK_H_

typedef struct s_list stack_t;

extern stack_t* stack_create(void);
extern void stack_delete(stack_t *stack);

extern void stack_push(stack_t *stack, void *data);
extern void stack_pop(stack_t *stack);

extern void* stack_top(stack_t *stack);

extern void stack_clear(stack_t *stack);

extern bool stack_is_empty(stack_t *stack);
extern size_t stack_size(stack_t *stack);

#endif // _STACK_H_
