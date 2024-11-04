/*
** EPITECH PROJECT, 2022
** my_file
** File description:
** BSQ
*/

#include "../include/my.h"
int test_line(bsq *biggest, char *buff, int size, int i);

int error_file(char *buff, int lines_nbr)
{
    bsq *biggest = malloc(sizeof(bsq));
    int i = 0, y_nbr = 0, j = line_size(buff), size = 0;
    for (; buff[i]; i++) {
        size++;
        if (buff[i] == '\n') {
                y_nbr++;
                biggest->size_saved = (y_nbr == 2) ?
                size : biggest->size_saved;
                size = 0;
            }
        }
    biggest->size_saved = biggest->size_saved * y_nbr, i = j;
    if (test_line(biggest, buff, size, i) == 84) return (84);
    if (lines_nbr <= 0 || lines_nbr + 1 != y_nbr)
        return (84);
    buff += j;
    for (j++; buff[j] && j < i; j++)
        if (buff[j] != '.' && buff[j] != 'o' && buff[j] != '\n')
            return (84);
    return (0);
}

int test_line(bsq *biggest, char *buff, int size, int i)
{
    int j = i;
    for (; buff[i]; i++) {
        size++;
        if (buff[i] == '\n') {
                biggest->size_saved -= size;
                size = 0;
            }
        }
    if (biggest->size_saved - line_size(buff + j) != 0)
        return (84);
    return (0);
}

char **malloc_my_map(char *buff, int y_nbr)
{
    int k = line_size(buff), i = 0, j = 0, l = 0;
    char **str = malloc(sizeof(char *) * (y_nbr + 2));

    while (i < y_nbr) {
        str[i] = malloc(sizeof(char) * (k + 2));
        for (j = 0; buff[l] != '\n'; l++, j++)
            str[i][j] = buff[l];
        str[i][j] = buff[l];
        j++, l++;
        str[i][j] = '\0';
        i++;
    }
    return (str);
}
