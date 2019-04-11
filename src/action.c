/*
** EPITECH PROJECT, 2018
** push swap
** File description:
** action of push swap
*/

#include "my.h"

void first_to_end(node_t **l_a)
{
    *l_a = (*l_a)->next;
}

void end_to_first(node_t **l_a)
{
    *l_a = (*l_a)->prev;
}

void delete_cond(node_t **from)
{
    if (*from == (*from)->next) {
        (*from) = NULL;
    } else {
        (*from)->prev->next = (*from)->next;
        (*from)->next->prev = (*from)->prev;
        (*from) = (*from)->next;
    }
}

void push_to_list(node_t **from, node_t **to)
{
    node_t *save;
    node_t *stock;

    if (*from == NULL)
        return;
    save = *from;
    delete_cond(from);
    if ((*to) != NULL) {
        stock = (*to)->prev;
        (*to)->prev = save;
        (*to)->prev->next = (*to);
        (*to)->prev->prev = stock;
        (*to)->prev->prev->next = save;
        *to = (*to)->prev;
    }
    else {
        (*to) = save;
        (*to)->next = (*to);
        (*to)->prev = (*to);
    }
}
