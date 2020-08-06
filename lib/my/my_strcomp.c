/*
** EPITECH PROJECT, 2020
** my_strcomp.c
** File description:
** compare two string
*/

#include "../../include/my.h"

int my_strcomp(char *str1, char *str2)
{
    int i = 0;

    while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0')) {
        i++;
    }
    return (str1[i] - str2[i]);
}
