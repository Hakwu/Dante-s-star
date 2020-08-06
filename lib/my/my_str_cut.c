/*
** EPITECH PROJECT, 2020
** my_str_cut.c
** File description:
** cut the string
*/

#include "../../include/my.h"

char *my_str_cut(char *path, int start, int j)
{
    int lengh = my_strlen(path);

    for (int c = 0; c != lengh; c++, start++) {
        path[c] = path[start];
    }
    path[j] = '\0';
    return (path);
}
