/*
** EPITECH PROJECT, 2020
** my_linked_list
** File description:
** linked
*/

#include "../../include/my.h"

int print_my_list(list *linked_list)
{
    if (linked_list == NULL)
        return (84);
    pos *current = linked_list->first;
    while (current != NULL) {
        my_putstr("x :");
        my_put_nbr(current->x);
        my_putstr("\ny :");
        my_put_nbr(current->y);
        my_putchar('\n');
        current = current->next;
    }
    return (0);
}

int insert(list *linked_list, int x, int y)
{
    pos *new = malloc(sizeof(new));
    if (linked_list == NULL || new == NULL)
        return (84);
    new->x = x;
    new->y = y;
    new->next = linked_list->first;
    linked_list->first = new;
    return (0);
}

list *init(void)
{
    list *linked_list = malloc(sizeof(list));
    pos *my_pos = malloc(sizeof(pos));
    if (linked_list == NULL || my_pos == NULL)
        return NULL;
    my_pos->x = 0;
    my_pos->y = 0;
    my_pos->next = NULL;
    linked_list->first = my_pos;
    return (linked_list);
}
