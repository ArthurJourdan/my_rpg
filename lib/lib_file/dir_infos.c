/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** dir_infos.c
*/

#include "my.h"
#include "file.h"

static char *send_filepath(DIR *directory, unsigned char type)
{
    struct dirent *act = NULL;

    do {
        act = readdir(directory);
        if (!act)
            return NULL;
    } while (act->d_type != type || act->d_name[0] == '.');
    return act->d_name;
}

char **get_filepaths(char *dirpath, unsigned char type)
{
    DIR *directory = NULL;
    char *fp = NULL;
    char **filepaths = NULL;
    size_t nb_files = nb_in_dir(dirpath, type);

    if (!nb_files)
        return NULL;
    filepaths = malloc(sizeof(char *) * (nb_files + 1));
    directory = opendir(dirpath);
    fp = send_filepath(directory, type);
    for (size_t a = 0; fp && a < nb_files; a++) {
        filepaths[a] = my_strcat_path(dirpath, fp);
        fp = send_filepath(directory, type);
    }
    filepaths[nb_files] = NULL;
    closedir(directory);

    return filepaths;
}

char **get_filepaths_maps(char *dirpath, unsigned char type)
{
    DIR *directory = NULL;
    char *fp = NULL;
    char **filepaths = NULL;
    size_t nb_files = nb_in_dir(dirpath, type);

    if (!nb_files)
        return NULL;
    filepaths = malloc(sizeof(char *) * (nb_files + 1));
    directory = opendir(dirpath);
    fp = send_filepath(directory, type);
    for (size_t a = 0; fp && a < nb_files - 1;) {
        if (get_pos_word_end_in_str("collision", fp))
            filepaths[nb_files - 1] = my_strcat_path(dirpath, fp);
        else
            filepaths[a++] = my_strcat_path(dirpath, fp);
        fp = send_filepath(directory, type);
    }
    filepaths[nb_files] = NULL;
    closedir(directory);
    sort_arr_alphabetically(filepaths);
    return filepaths;
}
