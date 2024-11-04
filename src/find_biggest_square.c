/*
** EPITECH PROJECT, 2022
** find_biggest_square
** File description:
** BSQ
*/
#include "../include/my.h"

int display_bsq(char **str, int values[3])
{
    int i = 0, left = values[0], right = values[2];
    int square_size = values[1], returned = 0;

    while (i <= left) {
        for (int x = 0; x <= left; x++) {
                returned = str[right + i][square_size + x]
                != '.' ? 1 : returned;
                str[right + i][square_size + x] = 'x';
            }
        i++;
    }
    return (returned);
}

int is_it_square(char **str, int x, int y, int line_square)
{
    for (int i = 0; i <= line_square; i++) {
        if (str[y + line_square][x + i] == 'o'
        || str[y + i][x + line_square] == 'o') {
            return (1);
        }
    }
    return (0);
}

void compare_square(bsq *biggest, int x, int y, int values[3])
{
    int line_square = 0;

    while (y + line_square < biggest->line_nbr
    && biggest->str[y + line_square][x + line_square] != '\n') {
        if (is_it_square(biggest->str, x, y, line_square)) {
            return;
        }
        check(line_square++, x, y, values);
    }
}

void check(int line_square, int x, int y, int values[3])
{
    if (line_square > values[0]) {
        values[0] = line_square;
        values[1] = x;
        values[2] = y;
    }
}

int find_bsq(bsq *biggest, int values[3])
{
    int x = 0, y = 0, returned = 0;

    for (;y < biggest->line_nbr; y++) {
        for (x = 0; biggest->str[y][x] != '\n'; x++) {
            returned = (biggest->str[y][x] != '.' && biggest->str[y][x] != 'o'
            && biggest->str[y][x] != '\n') ? 1 : returned;
            compare_square(biggest, x, y, values);
        }
    }
    return (returned);
}
