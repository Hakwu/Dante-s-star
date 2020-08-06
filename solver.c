/*
** EPITECH PROJECT, 2020
** my_maze.c
** File description:
** maz
*/

#include <time.h>
#include "include/my.h"

int my_engine_s(all_s *all)
{
    while (1) {
        my_init_engine(all);
        my_neighbour(all);
        all->data->neighbour[0][all->data->len_d] = 4;
        if (all->data->neighbour[0][0] != 4) {
            my_take_dir(all);
        } else {
            pop(&all->root);
            if (!is_empty(all->root)) {
                all->data->my_int_maze[all->data->pos_y][all->data->pos_x] = 3;
                all->data->pos_x = peek(all->root, 0);
                all->data->pos_y = peek(all->root, 1);
            }
            if (is_empty(all->root)) {
                my_putstr("no solution found\n");
                return (1);
            }
        }
        if (all->data->my_int_maze[all->data->y - 1][all->data->x - 2] == 2)
            break;
    }
}

void my_display_maze_s(all_s *all)
{
    for (int i = 0; i != all->data->y; i++) {
        for (int j = 0; j != all->data->x - 1; j++) {
            if (all->data->my_int_maze[i][j] == 2)
                all->data->my_maze[i][j] = 'o';
        }
        my_putstr(all->data->my_maze[i]);
    }
}

char **my_maze(char *path, all_s *all)
{
    if (my_init(all, path) == 1)
        return (NULL);
    my_malloc_solver(all);
    my_get_int_maze(all);
    char **hello = malloc(sizeof(char *) * 1);
    hello[0] = "EXIT";
    if (my_engine_s(all) == 1)
        return (hello);
    my_display_maze_s(all);
}

int main(int ac, char **av)
{
    all_s *all = malloc(sizeof(all_s));
    all->data = malloc(sizeof(data_s));
    if (ac != 2)
        return (84);
    if (my_maze(av[1], all) == NULL)
        return (84);
    else
        return (0);
}
