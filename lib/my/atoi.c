/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** convert char * to int
*/

int my_atoi(char const *str)
{
    int nb = 0;
    int neg = 0;

    if (str[0] == '-') {
        neg = 1;
        str++;
    }
    for (int i = 0; str[i] != '\0'; i ++)
        nb = (nb * 10) + (str[i] - '0');
    if (neg == 1)
        nb = -nb;
    return (nb);
}
