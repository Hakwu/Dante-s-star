/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** put a nbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    else  if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return (0);
}
