/*
** EPITECH PROJECT, 2018
** push swap
** File description:
** struct for push swap
*/

#ifndef STRUCT_
#define STRUCT_

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node_t;

typedef struct save
{
    int i;
    int k;
}save_t;

#endif
