#include <stdio.h>
#include <stdint.h>

#ifndef _STRING_H_
#define _STRING_H_

typedef struct string string_t;

string_t* str_create(const size_t length);
void str_delete(string_t *str);

string_t* str_dupc(const char *str);
string_t* str_dup(const string_t *str);

void str_catc(string_t *dst, const char *src);
void str_cat(string_t *dst, const string_t *src);

void str_cpyc(string_t *dst, const char *src);
extern void str_cpy(string_t *dst, const string_t *src);

uint8_t str_cmpc(const string_t *str_l, const char *str_r);
extern uint8_t str_cmp(const string_t *str_l, const string_t *str_r);

extern size_t str_length(const string_t *str);

extern char* str_to_c_str(const string_t *str);

uint16_t str_chr_pos(const string_t *str, const char chr);
extern char* str_chr_ptr(const string_t *str, const char chr);
void str_reverse(const string_t *str);

extern int str_print(FILE *out_stream, const string_t *str);
extern int str_println(FILE *out_stream, const string_t *str);

#endif // _STRING_H_
