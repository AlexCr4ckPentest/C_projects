#include <stdio.h>
#include <assert.h>

#include "include/str.h"
#include "include/list.h"

#define LIST_SIZE 3

/* Test of list */
void test_1(void)
{
    list_t *list = list_create();
    printf("test_1(): list created\n");

    for (int i = 0; i < LIST_SIZE; i++) {
        int expr = i * (i + i * 3);
        list_push_back(list, expr);
        printf("test_1(): push back: data=%d; list_size=%d\n", expr, list_size(list));
    }

    list_print(list, "data=%d\n", stdout);

    list_delete(list);
    printf("test_1(): list deleted\n");
}

/* Test of string */
void test_2(void)
{
    string_t *str = str_from_c_str("Hello world!");
    printf("test_2(): string created: length = %d\n", str_length(str));

    printf("test_2(): string data = %s\n", str_to_c_str(str));

    char *ptr_found = str_chr_ptr(str, 'w');
    char *ptr_not_found = str_chr_ptr(str, 'x');

    assert(*ptr_found != '\0');
    printf("test_2(): ptr_found data = %s\n", ptr_found);

    assert(*ptr_not_found == '\0');
    printf("test_2(): ptr_not_found data = %d\n", *ptr_not_found);

    str_delete(str);
    printf("test_2(): string deleted\n");
}

int main(void)
{
    test_2();
    return 0;
}
