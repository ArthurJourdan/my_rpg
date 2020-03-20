/*
** EPITECH PROJECT, 2020
** my_repo
** File description:
** file.h
*/

#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

bool is_file_openable(char const *filepath);

size_t file_len(char const *filepath);

size_t get_pos_word_in_str(char const  *word, char const *str);
size_t get_pos_word_end_in_str(char const *word, char const *str);
size_t get_pos_word_in_double_arr(char const *word, char const **arr);

char *get_entire_file(char const *filepath);
char **get_entire_file_double_arr(char const *filepath);

#endif /*FILE_H_*/
