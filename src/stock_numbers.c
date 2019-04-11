/*
** EPITECH PROJECT, 2018
** push_swap
** File description:
** stock_map
*/

#include "my.h"

void cond_list(char **av, node_t **node_first, node_t **node_last,
                node_t **node)
{
    node_t *node_sup;

    for (int i = 2; av[i] != NULL; i++) {
        node_sup = malloc(sizeof(node_t));
        node_sup->data = my_atoi(av[i]);
        node_sup->next = *node_first;
        (*node)->next = node_sup;
        *node_last = *node;
        *node = (*node)->next;
        (*node)->prev = *node_last;
    }
}

struct node *set_linked_list(char **av)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *node_last;
    node_t *node_first;

    node->data = my_atoi(av[1]);
    node->prev = node;
    node->next = node;
    node_first = node;
    node_last = node;
    cond_list(av, &node_first, &node_last, &node);
    node_last = node;
    node = node->next;
    node->prev = node_last;
    return (node);
}

void free_node(node_t **l_a, int len)
{
    node_t *tmp;

    for (int i = 0; i < len; i++) {
        tmp = *l_a;
        *l_a = (*l_a)->next;
        free(tmp);
    }
}
