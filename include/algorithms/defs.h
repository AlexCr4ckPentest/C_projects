#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifndef _DEFS_H_
#define _DEFS_H_

typedef bool (*comparator_int)(int, int);
typedef int (*filler_int)();
typedef bool (*predicate)(int);

#endif // _DEFS_H_