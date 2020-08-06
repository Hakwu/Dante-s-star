/*
** EPITECH PROJECT, 2020
** my_direction.c
** File description:
** direction
*/

#include "../../include/my.h"

void check1(all_s *all, int next_dir)
{
    if (next_dir == 2) {
        all->data->pos_x = peek(all->root, 0) + 2;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->check_visited[all->data->pos_y][all->data->pos_x - 1] = 1;
        all->data->check_visited[all->data->pos_y][all->data->pos_x] = 1;
    }
    if (next_dir == 3) {
        all->data->pos_x = peek(all->root, 0) - 2;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->check_visited[all->data->pos_y][all->data->pos_x + 1] = 1;
        all->data->check_visited[all->data->pos_y][all->data->pos_x] = 1;
    }
}

void check(all_s *all, int next_dir)
{
    if (next_dir == 0) {
        all->data->pos_y = peek(all->root, 1) - 2;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->check_visited[all->data->pos_y + 1][all->data->pos_x] = 1;
        all->data->check_visited[all->data->pos_y][all->data->pos_x] = 1;
    }
    if (next_dir == 1) {
        all->data->pos_y = peek(all->root, 1) + 2;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->check_visited[all->data->pos_y - 1][all->data->pos_x] = 1;
        all->data->check_visited[all->data->pos_y][all->data->pos_x] = 1;
    }
}
