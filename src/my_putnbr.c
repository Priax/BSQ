/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** BSQ
*/
#include "my.h"

void my_putnbr(int nb)
{
    if (nb == -2147483648)
        my_putstr("-2147483648");
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else
        my_putchar(48 + nb);
}
