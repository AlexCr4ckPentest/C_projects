#include "../include/str.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static string_t __str_create(const size_t length)
{
    string_t new_string;
    new_string.data = malloc(length * sizeof(char));

    *(new_string.data) = 0;
    new_string.p_end = new_string.data;
    new_string.length = 0;

    return new_string;
}



static string_t __str_substr_create(char *begin, char *end)
{
    string_t new_string;
    ptrdiff_t diff = end - begin;

    new_string.data = malloc(diff * sizeof(char) + 1);
    memcpy(new_string.data, begin, diff + 1);
    *(new_string.data + diff + 1) = '\0';
    new_string.p_end = (new_string.data + diff + 1);
    new_string.length = diff + 1;

    return new_string;
}



void str_delete(string_t *str)
{
    free(str->data);
    str->data = NULL;
}



string_t str_from_c_str(const char *str)
{
    string_t new_str = __str_create(strlen(str));
    str_cpyc(&new_str, str);
    return new_str;
}



string_t str_dupc(const char *str)
{
    size_t str_len = strlen(str);
    string_t dup = __str_create(str_len);

    memcpy(dup.data, str, str_len + 1);
    dup.p_end = (dup.data + str_len + 1);
    dup.length = str_len;

    return dup;
}



string_t str_dup(string_t *str)
{
    size_t str_len = str->length;
    string_t dup = __str_create(str_len);

    memcpy(dup.data, str->data, str_len + 1);
    dup.p_end = (dup.data + str_len + 1);
    dup.length = str_len;

    return dup;
}



void str_catc(string_t *dst, const char *src)
{
    char *new_dst_data = dst->p_end;

    while (*new_dst_data++ = *src++) {}
    *new_dst_data = '\0';
    
    dst->p_end = new_dst_data;
    dst->length += strlen(src);
}



void str_cat(string_t *dst, string_t *src)
{
    size_t src_len = src->length;
    size_t how_much = dst->length + src_len;

    dst->data = (char*) realloc(dst->data, how_much + 1);
    memcpy(dst->data + src_len, src->data, src_len + 1);

    dst->p_end = (dst->p_end + src_len + 1);
    dst->length += src_len;
}



void str_cpyc(string_t *dst, const char *src)
{
    size_t src_len = strlen(src);
    memcpy(dst->data, src, src_len + 1);
    dst->p_end = dst->data + src_len;
    dst->length = src_len;
}



void str_cpy(string_t *dst, string_t *src)
{
    size_t src_len = src->length;
    memcpy(dst->data, src->data, src_len + 1);
    dst->p_end = dst->data + src_len;
    dst->length = src_len;
}



bool str_cmpc(string_t *str_l, const char *str_r)
{
    if (str_l->length != strlen(str_r))
        return false;

    char *data_str_l = str_l->data;

    while (*data_str_l)
        if (*data_str_l++ != *str_r++)
            return false;
    return true;
}



bool str_cmp(string_t *str_l, string_t *str_r)
{
    if (str_l->length != str_r->length)
        return false;

    char *data_str_l = str_l->data;
    char *data_str_r = str_r->data;

    while (*data_str_l)
        if (*data_str_l++ != *data_str_r++)
            return false;
    return true;
}



inline size_t str_length(string_t *str)
{
    return str->length;
}



inline char* str_to_c_str(string_t *str)
{
    return str->data;
}



inline double str_to_f(string_t *str) 
{
    return atof(str->data);
}



inline int str_to_i(string_t *str)
{
    return (int)(str_to_f(str));
}



inline char str_at(string_t *str, const size_t pos) 
{
    assert(pos <= str->length);
    return (*(str->data + pos));
}



inline char* str_ptr_at(string_t *str, const size_t pos)
{
    assert(pos <= str->length);
    return (str->data + pos);
}



size_t str_chr_pos(string_t *str, const char chr)
{
    size_t chr_pos = 0;
    char *str_data = str->data;
    
    while (*str_data) {
        if (*str_data++ == chr)
            break;
        chr_pos++;
    }
    return chr_pos;
}



inline char* str_chr_ptr(string_t *str, const char chr)
{
    char *chr_ptr = (str->data + str_chr_pos(str, chr));
    return ((*chr_ptr) == '\0' ? NULL : chr_ptr);
}



void str_reverse(string_t *str)
{
    char tmp;
    for (int i = 0,j = str->length - 1; i < j; i++,j--) {
        tmp = str->data[i];
        str->data[i] = str->data[j];
        str->data[j] = tmp;
    }
}



string_t str_substr(string_t *str, const size_t begin, const size_t end) 
{
    assert(begin <= end);

    char *ptr_at_begin = str_ptr_at(str, begin);
    char *ptr_at_end = str_ptr_at(str, end);

    return __str_substr_create(ptr_at_begin, ptr_at_end);
}
