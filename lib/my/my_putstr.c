/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** put a string
*/

#include "../../include/my.h"

void my_putstr(char *str)
{
    int  i;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
