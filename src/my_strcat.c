/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** BSQ
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
