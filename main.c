#include <stdio.h>
#include <assert.h>

#include "include/str.h"
#include "include/list.h"
#include "include/stack.h"

/* TODO:
 * Make the test-cases for:
 *  1) string
 *  2) list (done)
 *  3) stack (done)
*/

void stack_test_case(void)
{
    stack_t *stack = stack_create();
    printf("stack_test_case(): stack created!, stack size: %ld\n", stack_size(stack));

    stack_push(stack, 100);
    printf("stack_test_case(): pushing %d, stack size: %ld\n", 100, stack_size(stack));

    stack_push(stack, 555);
    printf("stack_test_case(): pushing %d, stack size: %ld\n", 500, stack_size(stack));
    printf("stack_test_case(): stack top: %d\n", (int)stack_top(stack));

    stack_pop(stack);
    printf("stack_test_case(): pop() called! stack size: %ld\n", stack_size(stack));
    printf("stack_test_case(): stack top: %d\n", (int)stack_top(stack));

    stack_delete(stack);
}

void list_test_case(void)
{
    list_t *list = list_create();
    printf("list_test_case(): list created! list size: %ld\n", list_size(list));

    list_push_front(list, 100);
    printf("list_test_case(): pushing %d to front, list size: %ld\n", 100, list_size(list));

    list_push_back(list, 200);
    printf("list_test_case(): pushing %d to back, list size: %ld\n", 200, list_size(list));
    printf("list_test_case(): [0] = %d, [1] = %d\n", (int)list_at(list, 0), (int)list_at(list, 1));
    printf("list_test_case(): first = %d, last = %d\n", (int)list_first(list), (int)list_last(list));

    list_pop_front(list);
    printf("list_test_case(): pop front!, list size: %ld\n", list_size(list));

    list_push_back(list, 300);
    printf("list_test_case(): pushing %d to back, list size: %ld\n", 300, list_size(list));

    list_pop_back(list);
    printf("list_test_case(): pop back! list size: %ld\n", list_size(list));

    list_push_back(list, 400);
    printf("list_test_case(): pushing %d to back, list size: %ld\n", 400, list_size(list));
    printf("list_test_case(): [0] = %d, [1] = %d\n", (int)list_at(list, 0), (int)list_at(list, 1));

    list_reverse(list);
    printf("list_test_case(): revesing list!\n");
    printf("list_test_case(): [0] = %d, [1] = %d\n", (int)list_at(list, 0), (int)list_at(list, 1));

    list_delete(list);
}

void string_test_case(void)
{}

int main(void)
{
    stack_test_case();
    list_test_case();
    return 0;
}
