/*
** EPITECH PROJECT, 2020
** my_init_s.c
** File description:
** init solver
*/

#include <time.h>
#include "../../include/my.h"

off_t fsize(char *path) {
    struct stat sb;
    if (stat(path, &sb) == 0)
        return (sb.st_size);
    return (-1);
}

void my_get_value(all_s *all, char *buffer)
{
    for (int i = 0; buffer[i] != '\n'; i++)
        all->data->x++;
    all->data->x++;
    int p = 0;
    for (p = 0; buffer[p] != '\0'; p++) {
        if (buffer[p] == '\n')
            all->data->y++;
    }
    if (buffer[p - 1] != '\n')
        all->data->y++;
}

int my_init(all_s *all, char *path)
{
    all->root = NULL;
    srand((unsigned) time(NULL));
    int size = fsize(path);
    if (size == - 1 || size == 0)
        return (1);
    all->data->pos_x = 0;
    all->data->pos_y = 0;
    all->data->x = 0;
    all->data->y = 0;
    all->data->buffer = malloc(sizeof(char) * (size + 1));
    int fd = open(path, O_RDONLY);
    int rd = read(fd, all->data->buffer, size);
    push(&all->root, all->data->pos_x, all->data->pos_y);
    my_get_value(all, all->data->buffer);
}

void my_malloc_solver(all_s *all)
{
    int k = 0;
    all->data->my_maze = malloc(sizeof(char *) * (all->data->y + 1));
    all->data->my_int_maze = malloc(sizeof(int *) * (all->data->y + 1));
    for (int i = 0; i != all->data->y; i++) {
        all->data->my_maze[i] = malloc(sizeof(char) * (all->data->x + 1));
        all->data->my_int_maze[i] = malloc(sizeof(int) * (all->data->x + 1));
    }
    for (int i = 0; i != all->data->y; i++) {
        for (int j = 0; j != all->data->x; j++, k++) {
            if (all->data->buffer[k] == '*'
                || all->data->buffer[k] == 'X' || all->data->buffer[k] == '\n')
                all->data->my_maze[i][j] = all->data->buffer[k];
        }
    }
}

