#include <stdio.h>
#include "include/str.h"
#include "include/list.h"

void test_1(void)
{
    list_t *list = list_create();
    printf("test_1(): list created\n");

    for (int i = 0; i < 5; i++) {
        int expr = i * (i + i * 3);
        list_push_back(list, expr);
        printf("test_1(): push back: data=%d; list_size=%d\n",
                expr, list_size(list));
    }

    list_print(list, "data=%d\n", stdout);

    list_delete(list);
    printf("test_1(): list deleted\n");
}

int main(void)
{
    test_1();
    return 0;
}
