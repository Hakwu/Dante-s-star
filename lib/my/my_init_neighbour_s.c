/*
** EPITECH PROJECT, 2020
** my_init_neighbour_s.c
** File description:
** neighbour init
*/

#include "../../include/my.h"

void my_get_int_maze(all_s *all)
{
    for (int i = 0; i != all->data->y; i++) {
        for (int j = 0; j != all->data->x - 1; j++) {
            if (all->data->my_maze[i][j] == '*')
                all->data->my_int_maze[i][j] = 1;
            if (all->data->my_maze[i][j] == 'X')
                all->data->my_int_maze[i][j] = 0;
        }
    }
    all->data->my_int_maze[0][0] = 2;
}

void my_init_engine(all_s *all)
{
    all->data->len_d = 0;
    all->data->neighbour = malloc(sizeof(int *) * 1);
    for (int i = 0; i != 1; i++)
        all->data->neighbour[i] = malloc(sizeof(int) * 5);
}

void my_neighbour(all_s *all)
{
    if (all->root->y > 0
        && all->data->my_int_maze[all->root->y - 1][all->root->x] == 1) {
        all->data->neighbour[0][all->data->len_d] = 0;
        all->data->len_d++;
    }
    if (all->root->y <= all->data->y - 2
        && all->data->my_int_maze[all->root->y + 1][all->root->x] == 1) {
        all->data->neighbour[0][all->data->len_d] = 1;
        all->data->len_d++;
    }
    if (all->root->x <= all->data->x
        && all->data->my_int_maze[all->root->y][all->root->x + 1] == 1) {
        all->data->neighbour[0][all->data->len_d] = 2;
        all->data->len_d++;
    }
    if (all->root->x > 0
        && all->data->my_int_maze[all->root->y][all->root->x - 1] == 1) {
        all->data->neighbour[0][all->data->len_d] = 3;
        all->data->len_d++;
    }
}

void my_take_dir_right_left(all_s *all, int next_dir)
{
    if (next_dir == 2) {
        all->data->pos_x = peek(all->root, 0) + 1;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->my_int_maze[all->data->pos_y][all->data->pos_x] = 2;
    }
    if (next_dir == 3) {
        all->data->pos_x = peek(all->root, 0) - 1;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->my_int_maze[all->data->pos_y][all->data->pos_x] = 2;
    }
}

void my_take_dir(all_s *all)
{
    int next_dir = all->data->neighbour[0][rand() % all->data->len_d];
    if (next_dir == 0) {
        all->data->pos_y = peek(all->root, 1) - 1;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->my_int_maze[all->data->pos_y][all->data->pos_x] = 2;
    }
    if (next_dir == 1) {
        all->data->pos_y = peek(all->root, 1) + 1;
        push(&all->root, all->data->pos_x, all->data->pos_y);
        all->data->my_int_maze[all->data->pos_y][all->data->pos_x] = 2;
    }
    my_take_dir_right_left(all, next_dir);
}
