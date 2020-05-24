#include "defs.h"

#ifndef _COUNT_H_
#define _COUNT_H_

uint32_t single_count_if(int *arr_p, const size_t size, predicate pred);
uint32_t single_count_if_not(int *arr_p, const size_t size, predicate pred);

uint32_t double_count_if(int *arr_p, const size_t size, comparator_int comp);
uint32_t double_count_if_not(int *arr_p, const size_t size, comparator_int comp);

uint32_t summ_if(int *arr_p, const size_t size, predicate pred);
uint32_t summ_all(int *arr_p, const size_t size);

#endif // _COUNT_H_