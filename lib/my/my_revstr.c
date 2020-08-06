/*
** EPITECH PROJECT, 2020
** my_revstr.C
** File description:
** reverse a sting
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int maxi = 0;
    int wait = 0;

    while (str[maxi] != '\0')
        maxi++;
    maxi--;
    while (i < maxi) {
        wait = str[i];
        str[i] = str[maxi];
        str[maxi] = wait;
        i++;
        maxi--;
    }
    return (str);
}
