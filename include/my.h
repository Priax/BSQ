/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** BSQ
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_getnbr(const char *str);
int line_size(char *str);
int my_strlen(char const *str);
void my_putstr(char *str);
char **read_file(char *filepath, int *y_nbr);
char **malloc_my_map(char *buff, int y_nbr);
int error_file(char *buff, int lines_nbr);
int find_bsq(bsq *biggest, int values[3]);
int display_bsq(char **str, int values[3]);
void replace_square(char **str, int nb_cols, int b);
void display_map(char **str, int lines_nbr);
void check(int side, int x, int y, int values[3]);
char **generator(char *nbr, char *string);
char *modif_string(char *str);
int my_strlen_o(char *str);
int find_pattern(int nbr, int k);
void my_putnbr(int nb);
char **display_gen(int nbr, char **tab);
int biggest_generator(bsq *biggest, int *values, char **argv);
void malloc_my_map2(bsq *map);
char *my_strcat(char *dest, char const *src);

#endif /* MY_H_ */
