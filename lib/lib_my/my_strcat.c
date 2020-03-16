/*
** EPITECH PROJECT, 2020
** lib/my
** File description:
** my_strcat.c
*/

#include "my.h"

/*
  char *my_strcat_tot(int ac, ...)
  {
  va_list ap;
  int len_tot = 0;
  char *str = NULL;
  char *one = NULL;

  va_start(ap, ac);
  for (int a = 0; a < ac; a++) {
  len_tot = my_len_tot(va_arg(ap, char *));
  }
  va_end(ap);
  str = malloc(sizeof(char) * (len_tot + 1));
  if (!str)
  return NULL;
  len_tot = 0;
  va_start(ap, ac);
  for (int a = 0; a < ac; a++) {
  one = va_arg(ap, char *);
  for (int len_one = 0; len_one < my_strlen(one);len_one++) {
  str[len_tot] = one[len_one];
  len_tot++;
  }
  }
  str[len_tot] = '\0';
  va_end(ap);
  return str;
  }
*/

char *my_strcat(char const *str1, char const *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int len3 = len1 + len2;
    char *str3 = malloc(sizeof(char) * (len3 + 2));

    for (int a = 0; a < len1; a++)
        *(str3 + a) = *(str1 + a);
    for (int b = 0; b < len2; b++)
        *(str3 + b + len1) = *(str2 + b);
    *(str3 + (len1 + len2)) = '\0';
    return str3;
}

char *my_strcat_free(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int len3 = len1 + len2;
    char *str3 = malloc(sizeof(char) * (len3 + 2));

    for (int a = 0; a < len1; a++)
        *(str3 + a) = *(str1 + a);
    for (int b = 0; b < len2; b++)
        *(str3 + b + len1) = *(str2 + b);
    *(str3 + (len1 + len2)) = '\0';
    free(str1);
//    free(str2);
    return str3;
}
