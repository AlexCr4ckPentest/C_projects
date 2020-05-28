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
    printf("(%s): stack created!, stack size: %ld\n", __FUNCTION__, stack_size(stack));

    stack_push(stack, 100);
    printf("(%s): pushing %d, stack size: %ld\n", __FUNCTION__, 100, stack_size(stack));

    stack_push(stack, 555);
    printf("(%s): pushing %d, stack size: %ld\n", __FUNCTION__, 500, stack_size(stack));
    printf("(%s): stack top: %d\n", __FUNCTION__, (int)stack_top(stack));

    stack_pop(stack);
    printf("(%s): pop() called! stack size: %ld\n", __FUNCTION__, stack_size(stack));
    printf("(%s): stack top: %d\n", __FUNCTION__, (int)stack_top(stack));

    stack_delete(stack);
}

void list_test_case(void)
{
    list_t *list = list_create();
    printf("(%s): list created! list size: %ld\n", __FUNCTION__, list_size(list));

    list_push_front(list, 100);
    printf("(%s): pushing %d to front, list size: %ld\n", __FUNCTION__, 100, list_size(list));

    list_push_back(list, 200);
    printf("(%s): pushing %d to back, list size: %ld\n", __FUNCTION__, 200, list_size(list));
    printf("(%s): [0] = %d, [1] = %d\n", __FUNCTION__, (int)list_at(list, 0), (int)list_at(list, 1));
    printf("(%s): first = %d, last = %d\n", __FUNCTION__, (int)list_first(list), (int)list_last(list));

    list_pop_front(list);
    printf("(%s): pop front!, list size: %ld\n", __FUNCTION__, list_size(list));

    list_push_back(list, 300);
    printf("(%s): pushing %d to back, list size: %ld\n", __FUNCTION__, 300, list_size(list));

    list_pop_back(list);
    printf("(%s): pop back! list size: %ld\n", __FUNCTION__, list_size(list));

    list_push_back(list, 400);
    printf("(%s): pushing %d to back, list size: %ld\n", __FUNCTION__, 400, list_size(list));
    printf("(%s): [0] = %d, [1] = %d\n", __FUNCTION__, (int)list_at(list, 0), (int)list_at(list, 1));

    list_reverse(list);
    printf("(%s): revesing list!\n", __FUNCTION__);
    printf("(%s): [0] = %d, [1] = %d\n", __FUNCTION__, (int)list_at(list, 0), (int)list_at(list, 1));

    list_delete(list);
}

void string_memory_leaks_test_case(void)
{
    string_t str = str_from_c_str("123");
    str_delete(&str);

    str = str_from_c_str("Goodbye world!");
    str_delete(&str);

    str = str_from_c_str("Hello world!");
    string_t dup = str_dup(&str);
    str_delete(&dup);

    str_delete(&str);
}

void string_concat_test_case(void)
{
    string_t str_1;
    string_t str_2;

    str_1 = str_from_c_str("Hello ");
    str_2 = str_from_c_str("world!");

    printf("(%s): concating '%s' and '%s'\n", __FUNCTION__, str_to_c_str(&str_1), str_to_c_str(&str_2));
    str_cat(&str_1, &str_2);
    printf("(%s): result: %s\n", __FUNCTION__, str_to_c_str(&str_1));

    str_delete(&str_2);
    str_delete(&str_1);
}

void string_substr_test_case(void)
{
    string_t str = str_from_c_str("Hello world!");
    string_t sub = str_substr(&str, 0, 4);

    printf("(%s): base string: %s\n", __FUNCTION__, str_to_c_str(&str));
    printf("(%s): substring: %s\n", __FUNCTION__, str_to_c_str(&sub));

    str_delete(&sub);
    str_delete(&str);
}

void string_find_test_case(void)
{
    string_t str = str_from_c_str("Hello world");

    char c_1 = 'w';
    char c_2 = 'x';

    char *p_1 = str_chr_ptr(&str, c_1);
    char *p_2 = str_chr_ptr(&str, c_2);

    if (p_1 != NULL) {
        printf("(%s): char '%c' was found in '%s'\n", __FUNCTION__, c_1, p_1);
    }
    else {
        printf("(%s): char '%c' was not found in string '%s'\n", __FUNCTION__, c_1, str_to_c_str(&str));
    }

    if (p_2 != NULL) {
        printf("(%s): char '%c' was found in '%s'\n", __FUNCTION__, c_2, p_2);
    }
    else {
        printf("(%s): char '%c' was not found in string '%s'\n", __FUNCTION__, c_2, str_to_c_str(&str));
    }

    str_delete(&str);
}

int main(void)
{
    return 0;
}
