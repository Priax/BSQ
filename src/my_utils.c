/*
** EPITECH PROJECT, 2022
** my_utils
** File description:
** BSQ
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int line_size(char *str)
{
    int i = 0;

    while (str[i] && str[i] != '\n') {
        i++;
    }
    return (i + 1);
}

int my_getnbr(const char *str)
{
    int n = 0;
    int signe = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '-' && signe == -1 && n == 0) ||
            (str[i] == '+' && n == 0))
            signe = 1;
        if (str[i] == '-' && n == 0)
            signe = -1;
        if ((str[i] < '0' || str[i] > '9') && n > 0)
            break;
        if ((str[i] < '0' || str[i] > '9') && n == 0)
            continue;
        n += str[i] - 48;
        n *= 10;
    }
    n /= 10;
    return (n * signe);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
