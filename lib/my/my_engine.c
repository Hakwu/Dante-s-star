/*
** EPITECH PROJECT, 2020
** my_engine.c
** File description:
** engine
*/

#include "../../include/my.h"

void my_engine(all_s *all)
{
    while (1) {
        my_init_neighbour(all);
        which_direction(all);
        all->data->neighbour[0][all->data->len_d] = 4;
        if (all->data->neighbour[0][0] != 4) {
            int next_dir = all->data->neighbour[0][rand() % all->data->len_d];
            check(all, next_dir);
            check1(all, next_dir);
        } else {
            pop(&all->root);
            if (!is_empty(all->root)) {
                all->data->pos_x = peek(all->root, 0);
                all->data->pos_y = peek(all->root, 1);
            }
            if (is_empty(all->root))
                break;
        }
    }
}

void my_imperfect(data_s *data, int x, int y)
{
    if (data->ac == 3) {
        data->maze[0][1] = '*';
        data->maze[1][0] = '*';
        data->maze[1][1] = '*';
        for (int i = 0; i != y; i++) {
            for (int j = 0; j != x; j++) {
            }
            my_putstr(data->maze[i]);
            if (i < y - 1)
                my_putchar('\n');
        }
    }
}

void my_display_maze(data_s *data, int x, int y)
{
    if (y % 2 == 0)
        data->maze[y - 1][x - 1] = '*';
    if (x % 2 == 0) {
        data->maze[y - 1][x - 2] = '*';
        data->maze[y - 1][x - 1] = '*';
    }
    my_imperfect(data, x, y);
    if (data->ac == 4) {
        for (int i = 0; i != y; i++) {
            for (int j = 0; j != x; j++) {
            }
            my_putstr(data->maze[i]);
            if (i < y - 1)
                my_putchar('\n');
        }
    }
}

void my_get_maze(all_s *all, int x, int y)
{
    for (int i = 0; i != y; i++) {
        for (int j = 0; j != x; j++) {
            if (all->data->check_visited[i][j] == 1)
                all->data->maze[i][j] = '*';
            else if (all->data->check_visited[i][j] == 0)
                all->data->maze[i][j] = 'X';
        }
    }
}
