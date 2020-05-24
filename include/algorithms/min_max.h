#include "defs.h"

#ifndef _MIN_MAX_H_
#define _MIN_MAX_H_

int get_min_index(int *restrict arr_p, const size_t size);
int get_max_index(int *restrict arr_p, const size_t size);

extern int get_min_value(int *restrict arr_p, const size_t size);
extern int get_max_value(int *restrict arr_p, const size_t size);

#endif // _MIN_MAX_H_