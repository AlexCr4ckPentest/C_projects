#include "../include/algorithms/algorithms.h"

inline static bool default_comparator_int(int n_1, int n_2)
{
    return (n_1 > n_2);
}



inline void swap_int(int *elem_1, int *elem_2)
{
    int tmp = *elem_1;
    *elem_1 = *elem_2;
    *elem_2 = tmp;
}



inline void fill_int(int *restrict arr_p, const size_t size, filler_int filler) 
{
    for (size_t i = 0; i < size; i++)
        *(arr_p + i) = filler();
}



void bubble_sort_int(int *arr_p, const size_t size, comparator_int comp)
{
    bool is_swapped;

    if (comp == NULL)
        comp = default_comparator_int;

    for (size_t i = 0; i < size - 1; i++) {
        is_swapped = false;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (comp(arr_p[j], arr_p[j + 1])) {
                swap_int(&arr_p[j], &arr_p[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped)
            break;
    }
}




int get_min_index(int *restrict arr_p, const size_t size)
{
    int min_index = 1;

    for (size_t i = 0; i < size; i++)
        if (*(arr_p + i) < *(arr_p + min_index))
            min_index = i;

    return min_index;
}



int get_max_index(int *restrict arr_p, const size_t size)
{
    int max_index = 1;

    for (size_t i = 0; i < size; i++)
        if (*(arr_p + i) > *(arr_p + max_index))
            max_index = i;

    return max_index;
}



inline int get_min_value(int *restrict arr_p, const size_t size)
{
    return (*(arr_p + get_min_index(arr_p, size)));
}



inline int get_max_value(int *restrict arr_p, const size_t size)
{
    return (*(arr_p + get_max_index(arr_p, size)));
}



uint32_t single_count_if(int *restrict arr_p, const size_t size, predicate pred)
{
    uint32_t counter = 0;

    for (size_t i = 0; i < size; i++)
        if (pred(arr_p[i]))
            counter++;

    return counter;
}



uint32_t single_count_if_not(int *restrict arr_p, const size_t size, predicate pred)
{
    uint32_t counter = 0;

    for (size_t i = 0; i < size; i++)
        if (!pred(arr_p[i]))
            counter++;

    return counter;
}



uint32_t double_count_if(int *restrict arr_p, const size_t size, comparator_int comp)
{
    uint32_t counter = 0;

    if (comp == NULL)
        comp = default_comparator_int;

    for (size_t i = 0; i < size - 1; i++)
        if (comp(arr_p[i], arr_p[i + 1]))
            counter++;

    return counter;
}



uint32_t double_count_if_not(int *restrict arr_p, const size_t size, comparator_int comp)
{
    uint32_t counter = 0;

    if (comp == NULL)
        comp = default_comparator_int;

    for (size_t i = 0; i < size - 1; i++)
        if (!comp(arr_p[i], arr_p[i + 1]))
            counter++;

    return counter;
}



uint32_t summ_if(int *restrict arr_p, const size_t size, predicate pred)
{
    uint32_t summ = 0;

    for (size_t i = 0; i < size; i++)
        if (pred(arr_p[i]))
            summ += arr_p[i];

    return summ;
}



uint32_t summ_all(int *restrict arr_p, const size_t size)
{
    uint32_t summ = 0;

    for (size_t i = 0; i < size; i++)
        summ += arr_p[i];

    return summ;
}



inline void copy(int *arr_dst, int *arr_src, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        arr_dst[i] = arr_src[i];
}



inline void reverse_copy(int *arr_dst, int *arr_src, const size_t size, predicate pred)
{
    for (size_t i = size - 1; i != 0; i++)
        arr_dst[i] = arr_src[i];
}



uint32_t copy_if(int *arr_dst, int *arr_src, const size_t size, predicate pred)
{
    uint32_t success_copied = 0;

    for (size_t i = 0; i < size; i++)
        if (pred(arr_src[i]))
            arr_dst[i] = arr_src[i];

    return success_copied;
}



uint32_t copy_if_not(int *arr_dst, int *arr_src, const size_t size, predicate pred)
{
    uint32_t success_copied = 0;

    for (size_t i = 0; i < size; i++)
        if (!pred(arr_src[i]))
            arr_dst[i] = arr_src[i];

    return success_copied;
}


uint32_t reverse_copy_if(int *arr_dst, int *arr_src, const size_t size, predicate pred)
{
    uint32_t success_count = 0;

    for (size_t i = size - 1; i != 0; i++)
        if (pred(arr_src[i]))
            arr_dst[i] = arr_src[i];

    return success_count;
}



uint32_t reverse_copy_if_not(int *arr_dst, int *arr_src, const size_t size, predicate pred)
{
    uint32_t success_count = 0;

    for (size_t i = size - 1; i != 0; i++)
        if (!pred(arr_src[i]))
            arr_dst[i] = arr_src[i];

    return success_count;
}
