/*
** EPITECH PROJECT, 2020
** my_maze.c
** File description:
** maz
*/

#include "include/my.h"
#include <time.h>

void my_malloc(data_s *data, int x, int y)
{
    data->maze = malloc(sizeof(char *) * y);
    for (int i = 0; i != y; i++)
        data->maze[i] = malloc(sizeof(char) * (x + 1));

    data->check_visited = malloc(sizeof(int *) * y);
    for (int i = 0; i != y; i++)
        data->check_visited[i] = malloc(sizeof(int) * x);
}

char **my_maze(int x, int y, all_s *all)
{
    my_malloc(all->data, x, y);
    all->root = NULL;
    srand((unsigned) time(NULL));
    all->data->check_visited[0][0] = 1;
    all->data->pos_x = 0;
    all->data->pos_y = 0;
    push(&all->root, all->data->pos_x, all->data->pos_y);
    if (x == 1 && y == 1) {
        my_putstr("*\n");
        return NULL;
    }
    my_engine(all);
    my_get_maze(all, x, y);
    my_display_maze(all->data, x, y);
}

int main(int ac, char **av)
{
    all_s *all = malloc(sizeof(all_s));
    all->data = malloc(sizeof(data_s));
    all->data->x = my_getnbr(av[1]);
    all->data->y = my_getnbr(av[2]);
    all->data->ac = ac;
    if (ac != 3 && ac != 4)
        return (84);
    if (ac == 3)
        my_maze(my_getnbr(av[1]), my_getnbr(av[2]), all);
    if (ac == 4 && my_strcomp("perfect", av[3]) == 0) {
        my_maze(my_getnbr(av[1]), my_getnbr(av[2]), all);
    }
}
