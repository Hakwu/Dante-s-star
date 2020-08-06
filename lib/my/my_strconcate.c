/*
** EPITECH PROJECT, 2020
** my_strconcate.c
** File description:
** concatenate
*/

#include "../../include/my.h"

char *my_strconcate(char *str1, char *str2)
{
    int lengh_str = my_strlen(str1) + my_strlen(str2);
    int lengh_str2 = my_strlen(str2);
    char *str_concate = malloc(sizeof(char) * 100000);
    int end = my_strlen(str1);
    int start2 = end + 1;
    int k = 0;

    for (int i = 0; i != end ; i++) {
        str_concate[i] = str1[i];
    }
    str_concate[end] = '/';
    for (int j = start2; j != lengh_str + 1; j++, k++) {
        str_concate[j] = str2[k];
    }
    return (str_concate);
}
