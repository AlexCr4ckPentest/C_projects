#include "../include/str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct string
{
    char *data;     // pointer to C-string
    char *p_end;    // pointer to end of string
    size_t length;  // current length of string
} string_t;

string_t* str_create(const size_t length)
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
    string_t *new_str = str_create(strlen(str));
    str_cpyc(new_str, str);
    return new_str;
}

string_t* str_dupc(const char *str)
{
    size_t str_len = strlen(str);
    string_t *dup = str_create(str_len);

    memcpy(dup->data, str, str_len + 1);
    dup->p_end = (dup->data + str_len + 1);
    dup->length = str_len;
    
    return dup;
}

string_t* str_dup(const string_t *str)
{
    string_t *dup = str_dupc(str->data);
    return dup;
}

void str_catc(string_t *dst, const char *src)
{
    char *new_dst_data = dst->p_end;

    while (*new_dst_data++ = *src++);

    *new_dst_data = '\0';
    dst->p_end = new_dst_data;
}

void str_cat(string_t *dst, const string_t *src)
{
    char *new_dst_data = dst->p_end;
    char *src_copy_secure;

    memcpy(src_copy_secure, src->data, src->length + 1);

    while (*new_dst_data++ = *src_copy_secure++);

    *new_dst_data = '\0';
    dst->p_end = new_dst_data;
}

void str_cpyc(string_t *dst, const char *src)
{
    size_t src_len = strlen(src);
    memcpy(dst->data, src, src_len);

    *(dst->data + src_len) = '\0';
    
    dst->p_end = dst->data + src_len;
    dst->length = src_len;
}

inline void str_cpy(string_t *dst, const string_t *src)
{
    str_cpyc(dst, src->data);
}

uint8_t str_cmpc(const string_t *str_l, const char *str_r)
{
    if (str_l->length != strlen(str_r))
        return 1;
    char *data_str_l = str_l->data;
    while (*data_str_l) {
        if (*data_str_l != *str_r)
            return 1;
        data_str_l++;
        str_r++;
    }
    return 0;
}

inline uint8_t str_cmp(const string_t *str_l, const string_t *str_r)
{
    return (str_cmpc(str_l, str_r->data));
}

inline size_t str_length(const string_t *str)
{
    return str->length;
}

inline char* str_to_c_str(const string_t *str)
{
    return str->data;
}

uint16_t str_chr_pos(const string_t *str, const char chr)
{
    size_t chr_pos = 0;
    char *str_data = str->data;

    while (*str_data) {
        if (*str_data == chr)
            break;
        str_data++;
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

inline int str_print(FILE *out_stream, const string_t *str)
{
    return (fprintf(out_stream, "%s", str->data));
}

inline int str_println(FILE *out_stream, const string_t *str)
{
    return (fprintf(out_stream, "%s\n", str->data));
}
