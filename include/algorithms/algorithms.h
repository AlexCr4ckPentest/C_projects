#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include "defs.h"

#include "sort.h"
#include "min_max.h"
#include "count.h"
#include "copy.h"

extern void fill_int(int *restrict arr_p, const size_t size, filler_int filler);
extern void swap_int(int *elem_1, int *elem_2);

#endif // _ALGORITHMS_H_