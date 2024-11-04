/*
** EPITECH PROJECT, 2022
** generator
** File description:
** BSQ
*/
#include "../include/my.h"

char **display_gen(int nbr, char **tab)
{
    int i = 0, j = 0;

    if (nbr == 1 && tab[0][0] != 'o') tab[0][0] = 'x';
    for (i = 0; i < nbr && j < nbr; i++, j++) {
        if (j == nbr) j = 0;
        my_strcat(tab[i], "\n");
    }
    return (tab);
}

void display_gen2(char **map, int lines_nbr)
{
    int i = 0, k = 0, size = my_strlen(map[0]) * (lines_nbr);
    char *new_map = malloc(sizeof(char) * (size + 1));

    new_map[size] = '\0';
    for (int j = 0; i < lines_nbr; j++, k++) {
        new_map[k] = map[i][j];
        if (map[i][j] == '\n') {
            free(map[i]);
            i++;
            j = -1;
        }
    }
    my_putstr(new_map);
    free(new_map);
}

int find_pattern(int nbr, int k)
{
    if (k == nbr) return (0);
    return (k);
}
