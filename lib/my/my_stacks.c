/*
** EPITECH PROJECT, 2020
** my_stacks.c
** File description:
** stack
*/

#include "../../include/my.h"

struct stacknode *new_node(int x, int y)
{
    struct stacknode *stacknode = (struct stacknode *)
        malloc(sizeof(struct stacknode));
    stacknode->x = x;
    stacknode->y = y;
    stacknode->next = NULL;
    return stacknode;
}

int is_empty(struct stacknode *root)
{
    return !root;
}

void push(struct stacknode **root, int x, int y)
{
    struct stacknode *stacknode = new_node(x, y);
    stacknode->next = *root;
    *root = stacknode;
}

int pop(struct stacknode **root)
{
    if (is_empty(*root))
        return (-2147483648);
    struct stacknode *temp = *root;
    *root = (*root)->next;
    int popped;
    popped = temp->x;
    free(temp);
    return (popped);
}

int peek(struct stacknode *root, int who)
{
    if (is_empty(root))
        return (-2147483648);
    if (who == 0)
        return (root->x);
    if (who == 1)
        return (root->y);
}
