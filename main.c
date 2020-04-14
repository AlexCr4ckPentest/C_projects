#include <stdio.h>
#include <assert.h>

#include "include/str.h"
#include "include/list.h"
#include "include/stack.h"

/* TODO:
 * Make the test-cases for:
 *  1) string
 *  2) list
 *  3) stack (done)
*/

void stack_test_case(void)
{
    stack_t *stack = stack_create();
    printf("stack_test_case(): stack created!, stack size: %d\n", stack_size(stack));

    stack_push(stack, 100);
    printf("stack_test_case(): pushing %d, stack size: %d\n", 100, stack_size(stack));
    stack_push(stack, 555);
    printf("stack_test_case(): pushing %d, stack size: %d\n", 500, stack_size(stack));
    

    printf("stack_test_case(): stack top: %d\n", (int)stack_top(stack));

    stack_pop(stack);
    printf("stack_test_case(): pop() called! stack size: %d\n", stack_size(stack));

    printf("stack_test_case(): stack top: %d\n", (int)stack_top(stack));

    stack_delete(stack);
}

int main(void)
{
    stack_test_case();
    return 0;
}
