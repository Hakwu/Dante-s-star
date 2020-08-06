/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contains prototype of all functions in libmy
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct stacknode {
    unsigned int x;
    unsigned int y;
    struct stacknode *next;
};

typedef struct pos pos;
struct pos
{
    unsigned int x;
    unsigned int y;
    pos *next;
};

typedef struct list list;
struct list
{
    pos *first;
};

typedef struct data_t
{
    int x;
    int y;
    char **maze;
    char **my_maze;
    int **my_int_maze;
    int **check_visited;
    int **neighbour;
    int len_d;
    int pos_x;
    int pos_y;
    int ac;
    char *buffer;
}data_s;

typedef struct all_t
{
    list *my_list;
    data_s *data;
    struct stacknode *root;
}all_s;

void my_putchar(char c);
int my_put_nbr(int);
void my_putstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
char *my_str_cut(char *path, int start, int j);
char *my_strconcate(char *str1, char *str2);
int my_strcomp(char *str1, char *str2);
char *my_revstr(char *str);
char *my_itoa(int num);
int print_my_list(list *linked_list);
int insert(list *linked_list, int x, int y);
list *init(void);
struct stacknode *new_node(int x, int y);
int is_empty(struct stacknode *root);
void push(struct stacknode **root, int x, int y);
int pop(struct stacknode **root);
int peek(struct stacknode *root, int who);
void my_init_neighbour(all_s *all);
void which_direction(all_s *all);
void check(all_s *all, int next_dir);
void check1(all_s *all, int next_dir);
void my_engine(all_s *all);
void my_display_maze(data_s *data, int x, int y);
void my_get_maze(all_s *all, int x, int y);
off_t fsize(char *path);
void my_get_value(all_s *all, char *buffer);
int my_init(all_s *all, char *path);
void my_malloc_solver(all_s *all);
void my_get_int_maze(all_s *all);
void my_init_engine(all_s *all);
void my_neighbour(all_s *all);
void my_take_dir(all_s *all);
