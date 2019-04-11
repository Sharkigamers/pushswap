/*
** EPITECH PROJECT, 2018
** push swap
** File description:
** Proto
*/

#ifndef MY_
#define MY_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"

/* lib */

int my_atoi(char const *str);

/* action */

void first_to_end(node_t **l_a);
void end_to_first(node_t **l_a);
void push_to_list(node_t **from, node_t **to);

/* stock */

struct node *set_linked_list(char **av);
void cond_list(char **av, node_t **node_first, node_t **node_last,
                node_t **node);
void free_node(node_t **l_a, int len);

#endif
