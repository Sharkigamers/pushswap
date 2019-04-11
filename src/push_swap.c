/*
** EPITECH PROJECT, 2018
** push_swap
** File description:
** fct of push swap
*/

#include "my.h"

void disp_lista(node_t *l_a, int ac)
{
    for (int j = 1; j < ac;j++) {
        if (l_a == NULL) {
            printf("l_a : NULL\n");
            return;
        }
        printf("l_a : %d\n", l_a->data);
        l_a = l_a->next;
    }
}

void disp_listb(node_t *l_b, int ac)
{
    for (int j = 1; j < ac;j++) {
        if (l_b == NULL) {
            printf("l_b : NULL\n");
            return;
        }
        printf("l_b : %d\n", l_b->data);
        l_b = l_b->next;
    }
}

int cond_sorted_list(node_t *l_a, int len)
{
    int count = 0;

    for (int j = 1; j < len; j++) {
        if (l_a->data > l_a->next->data)
            count++;
        l_a = l_a->next;
    }
    l_a = l_a->next;
    if (count == 0)
        return (0);
    return (1);
}

void cond_pos(node_t **l_a, node_t **l_b, save_t *save, int len)
{
    for (int j = 1; j <= len; j++) {
        if (((*l_a)->data >> save->i) & 1) {
            push_to_list(l_a, l_b);
            first_to_end(l_b);
            write(1, "pb rb ", 6);
            save->k++;
        }
        else {
            first_to_end(l_a);
            write(1, "ra ", 3);
        }
    }
    if (l_b != NULL) {
        for (int j = 0; j < save->k; j++) {
            push_to_list(l_b, l_a);
            write(1, "pa ", 3);
            first_to_end(l_a);
            write(1, "ra ", 3);
        }
    }
}

void cond_neg(node_t **l_a, node_t **l_b, save_t *save, int len)
{
    for (int j = 1; j <= len; j++) {
        if (((*l_a)->data >> 31) & 1) {
            push_to_list(l_a, l_b);
            write(1, "pb ", 3);
            save->k++;
        }
        else {
            first_to_end(l_a);
            write(1, "ra ", 3);
        }
    }
    if (l_b != NULL) {
        for (int j = 0; j < save->k; j++) {
            push_to_list(l_b, l_a);
            write(1, "pa ", 3);
        }
    }
}

void push_swap(int ac, char **av)
{
    node_t *l_a = set_linked_list(av);
    node_t *l_b = NULL;
    int len = ac - 1;
    save_t save;

    if (cond_sorted_list(l_a, len) == 0) {
        write(1, "\n", 1);
        free_node(&l_a, len);
        return;
    }
    for (save.i = 0; save.i < 31; save.i++) {
        save.k = 0;
        cond_pos(&l_a, &l_b, &save, len);
    }
    save.k = 0;
    cond_neg(&l_a, &l_b, &save, len);
    write(1, "rb\n", 3);
    disp_lista(l_a, ac);
    disp_listb(l_b, ac);
    free_node(&l_a, len);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (84);
    else
    push_swap(ac, av);
    return (0);
}
