#include "../include/str.h"
#include <stdlib.h>
#include <string.h>

typedef struct string
{
    char *data;     // pointer to C-string
    char *p_end;    // pointer to end of string
    size_t length;  // current length of string
} string_t;



static string_t* __str_create(const size_t length)
{
    string_t *new_string = malloc(sizeof(string_t));
    new_string->data = malloc(length * sizeof(char));

    *(new_string->data) = 0;
    new_string->p_end = new_string->data;
    new_string->length = 0;

    return new_string;
}



void str_delete(string_t *str)
{
    free(str->data);
    free(str);
    str = NULL;
}



string_t* str_from_c_str(const char *str)
{
    string_t *new_str = __str_create(strlen(str));
    str_cpyc(new_str, str);
    return new_str;
}



string_t* str_dupc(const char *str)
{
    size_t str_len = strlen(str);
    string_t *dup = __str_create(str_len);

    memcpy(dup->data, str, str_len + 1);
    dup->p_end = (dup->data + str_len + 1);
    dup->length = str_len;

    return dup;
}



string_t* str_dup(const string_t *str)
{
    size_t str_len = str->length;
    string_t *dup = __str_create(str_len);

    memcpy(dup->data, str->data, str_len + 1);
    dup->p_end = (dup->data + str_len + 1);
    dup->length = str_len;

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



void str_cat(string_t *dst, const string_t *src)
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



void str_cpy(string_t *dst, const string_t *src)
{
    size_t src_len = src->length;
    memcpy(dst->data, src->data, src_len + 1);
    dst->p_end = dst->data + src_len;
    dst->length = src_len;
}



uint8_t str_cmpc(const string_t *str_l, const char *str_r)
{
    if (str_l->length != strlen(str_r))
        return 1;

    char *data_str_l = str_l->data;

    while (*data_str_l)
        if (*data_str_l++ != *str_r++)
            return 1;
    return 0;
}



uint8_t str_cmp(const string_t *str_l, const string_t *str_r)
{
    if (str_l->length != str_r->length)
        return 1;

    char *data_str_l = str_l->data;
    char *data_str_r = str_r->data;

    while (*data_str_l)
        if (*data_str_l++ != *data_str_r++)
            return 1;
    return 0;
}



inline size_t str_length(const string_t *str)
{
    return str->length;
}



inline char* str_to_c_str(const string_t *str)
{
    return str->data;
}



size_t str_chr_pos(const string_t *str, const char chr)
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



inline char* str_chr_ptr(const string_t *str, const char chr)
{
    return (str->data + str_chr_pos(str, chr));
}



void str_reverse(const string_t *str)
{
    char tmp;
    for (int i = 0,j = str->length - 1; i < j; i++,j--) {
        tmp = str->data[i];
        str->data[i] = str->data[j];
        str->data[j] = tmp;
    }
}
