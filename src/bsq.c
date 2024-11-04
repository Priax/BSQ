/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    bsq *biggest = malloc(sizeof(bsq) + 1);
    int b, values[3] = {0, 0, 0};
    if (argc < 2 || argc > 3) {
        my_putstr("Input a filename after ./bsq\n");
        return (84);
    }
    if (argc == 2) {
        biggest->str = read_file(argv[1], &biggest->line_nbr);
        if (biggest->str == NULL) return (84);
        b = biggest->str[0][0] == 'o' ? 1 : 0;
        if (find_bsq(biggest, values) == 1) return (84);
        display_bsq(biggest->str, values);
        if (values[0] == 0 && values[1] == 0 && values[2] == 0)
            replace_square(biggest->str, biggest->line_nbr, b);
        display_map(biggest->str, biggest->line_nbr), free(biggest->str);

    }
    if (argc == 3) {
        if (biggest_generator(biggest, values, argv) == 84) return (84);
    } free(biggest); return (0);
}

int biggest_generator(bsq *biggest, int *values, char **argv)
{
    int b = 0;
    biggest->str = generator(argv[1], argv[2]);
    if (biggest->str == NULL) return (84);
    b = biggest->str[0][0] == 'o' ? 1 : 0;
    biggest->line_nbr = my_getnbr(argv[1]);
    biggest->str = display_gen(biggest->line_nbr, biggest->str);
    find_bsq(biggest, values);
    display_bsq(biggest->str, values);
    if (values[0] == 0 && values[1] == 0 && values[2] == 0)
        replace_square(biggest->str, biggest->line_nbr, b);
    display_map(biggest->str, biggest->line_nbr);
    return (0);
}

char **generator(char *nb, char *str)
{
    int nbr = my_getnbr(nb), returned = 0;
    if (nbr <= 0 || *str == '\0') return (NULL);
    int i = 0, j = 0, k = 0;
    char **tab = malloc(sizeof(char *) * (nbr + 2));
    for (i = 0; i < nbr; i++) {
        tab[i] = malloc(sizeof(char) * (nbr + 2));
        for (j = 0; j < nbr; j++) {
            returned = (str[k] != '.' && str[k] != 'o') ? 1 : returned;
            tab[i][j] = str[k], k++;
            k = find_pattern(my_strlen(str), k);
        } tab[i][nbr] = '\0';
    }
    tab[nbr] = NULL, j = 0;
    if (returned == 1) return (NULL);
    return (tab);
}
