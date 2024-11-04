/*
** EPITECH PROJECT, 2022
** show_bsq
** File description:
** BSQ
*/

#include "../include/my.h"

void display_map(char **map, int lines_nbr)
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

int file_erro(char *filepath, int fd)
{
    struct stat info;
    bsq bs;
    if (stat(filepath, &info) < 0) {
        my_putstr("Please input an existing filepath\n");
        return (84);
    }
    bs.buff = malloc(sizeof(char) * (info.st_size + 1));
    bs.buff[info.st_size] = '\0';
    if ((fd = open(filepath, O_RDONLY)) <= -1)
        return (84);
    if (S_ISDIR(info.st_mode)) {
        return (84);
    }
    read(fd, bs.buff, info.st_size);
    close(fd);
    return (0);
}

char **read_file(char *filepath, int *y_nbr)
{
    struct stat info;
    int fd = open(filepath, O_RDONLY);
    char *buff, **map;

    if (file_erro(filepath, fd) == 84)
        return (NULL);
    stat(filepath, &info);
    if (info.st_size <= 0) return (NULL);
    buff = malloc(sizeof(char) * (info.st_size + 1));
    buff[info.st_size] = '\0';
    fd = open(filepath, O_RDONLY);
    read(fd, buff, info.st_size);
    close(fd);
    *y_nbr = my_getnbr(buff);
    if (error_file(buff, *y_nbr) == 84) return (NULL);
    map = malloc_my_map(buff + line_size(buff), *y_nbr);
    free(buff);
    return (map);
}

void replace_square(char **map, int nb_cols, int b)
{
    int i = 0, j = 0;
    if (b) map[0][0] = 'o';
    while (i < nb_cols) {
        if (map[i][j] == '.' || map[i][j] == 'x') {
            map[i][j] = 'x';
            return;
        }
        if (map[i][j] == '\n') {
            i++;
            j = -1;
        }
        j++;
    }
}
