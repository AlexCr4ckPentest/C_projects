#include "defs.h"

#ifndef _COPY_H_
#define _COPY_H_

extern void copy(int *arr_dst, int *arr_src, const size_t size);

uint32_t copy_if(int *arr_dst, int *arr_src, const size_t size, predicate pred);
uint32_t copy_if_not(int *arr_dst, int *arr_src, const size_t size, predicate pred);

#endif // _COPY_H_