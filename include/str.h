#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef _STR_H_
#define _STR_H_

/// !!! WARNING !!! DO NOT CHANGE THE FIELDS MANUALLY !!!
typedef struct string
{
    char *data;     // pointer to C-string
    char *p_end;    // pointer to end of string
    size_t length;  // current length of string
} string_t;

void str_delete(string_t *str);

string_t str_from_c_str(const char *str);

/// ----------------------------------------------------------------------------------
/// !!! WARNING !!! ALLOCATES MEMORY WITHOUT free() !!! for delete - use str_delete()
string_t str_dupc(const char *str);
string_t str_dup(string_t *str);
/// ----------------------------------------------------------------------------------

void str_catc(string_t *dst, const char *src);
void str_cat(string_t *dst, string_t *src);

void str_cpyc(string_t *dst, const char *src);
void str_cpy(string_t *dst, string_t *src);

bool str_cmpc(string_t *str_l, const char *str_r);
bool str_cmp(string_t *str_l, string_t *str_r);

extern size_t str_length(string_t *str);

extern char* str_to_c_str(string_t *str);
extern double str_to_f(string_t *str);
extern int str_to_i(string_t *str);

extern char str_at(string_t *str, const size_t pos);
extern char* str_ptr_at(string_t *str, const size_t pos);

size_t str_chr_pos(string_t *str, const char chr);
extern char* str_chr_ptr(string_t *str, const char chr);
void str_reverse(string_t *str);

/// ----------------------------------------------------------------------------------
/// !!! WARNING !!! ALLOCATES MEMORY WITHOUT free() !!! for delete - use str_delete()
string_t str_substr(string_t *str, const size_t begin, const size_t end);
/// ----------------------------------------------------------------------------------

#endif // _STR_H_