/*
** EPITECH PROJECT, 2020
** my_getfloat.c
** File description:
** get the first float occurence
*/

#include "my.h"

int next_dot(char *str)
{
    int counter = 0;

    while (str[counter] != ',' && str[counter] != '.' && str[counter])
        counter++;
    return counter;
}

int count_numb(int nb)
{
    int counter = 0;

    while (nb > 0) {
        nb /= 10;
        counter++;
    }
    return counter;
}

float power(int nb, int pow)
{
    if (!pow)
        return 1;
    return (nb * power(nb, pow - 1));
}

float my_getfloat(char *str)
{
    int left = my_getnbr(str);
    int right = my_getnbr(str + next_dot(str));
    float result = left + right / power(10, count_numb(right));

    return result;
}
