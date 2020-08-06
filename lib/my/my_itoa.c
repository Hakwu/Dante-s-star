/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** str to int
*/

#include "../../include/my.h"

static int sign(int num)
{
    if (num < 0)
        return (-num);
    else
        return (num);
}

static int my_malloc(char **str, int num)
{
    int i = 0;
    if (num < 0)
        i = 1;
    while (num < -9 || num > 9)
    {
        num = num / 10;
        i++;
    }
    if (!(*str = malloc(sizeof(char) * (i + 2))))
        return (0);
    (*str)[i + 1] = '\0';
    return (i + 1);
}

char *my_itoa(int num)
{
    char *str_num = malloc(num);
    int j = 0;

    if (!(j = my_malloc(&str_num, num)))
        return (NULL);
    while (num < - 9 || num > 9) {
        str_num[j - 1] = sign(num % 10) + 48;
        num = num / 10;
        j--;
    }
    str_num[j - 1] = sign(num % 10) + 48;
    if (num < 0)
        str_num[0] = '-';
    return (str_num);
}
