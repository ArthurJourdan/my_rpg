/*
** EPITECH PROJECT, 2019
** my
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#include <errno.h>
#include <string.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

#undef EXIT_FAILURE
#define EXIT_FAILURE 84

#define USELESS __attribute__((unused))

int my_strlen(char const *str);
int my_arrlen(char ** const arr);
int my_len_tot(char const *str);

int my_getnbr(char *str);
float my_getfloat(char *str);
int my_getdigit(char nb);

char *my_strcat(char const *str1, char const *str2);
char *my_strcat_free(char *str1, char *str2);
char *my_strcat_path(char const *str1, char const *str2);

char **my_str_to_word_arr(char *str);

bool my_strcmp(char const *str_1, char const *str_2);
bool my_str_n_cmp(char const *str_1, char const *str_2, int len);

char **my_double_arr_cpy(char **double_arr);

bool my_char_is_alpha_num(char const c, bool alpha, bool num, bool up);
bool my_str_is_alphanum(char const *str);
bool my_str_is_alpha(char const *str);
bool my_str_is_upper(char const *str);
bool my_str_is_num(char const *str);
bool my_char_is_nothing(char const c, bool alpha, bool num, bool up);
bool my_str_is_nothing(char const *str);

bool error_msg(int ac, char **av);

char *my_strcpy(char *str);
char *my_str_n_cpy(char *str, int size);
char *my_str_cpy_until_char(char *str, char c);
char *my_str_cpy_quotation(char *str);

void free_double_char_arr(char **arr);
char *free_char_to_null(char *str);

char *my_reg_nbr(int nb);

#endif /*MY_H_*/
