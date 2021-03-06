/*
** EPITECH PROJECT, 2021
** ib_strcpy
** File description:
** returns a copy of the string given as a parameter
*/

#include <stdlib.h>
#include "../../includes/ib.h"

char *ib_strcpy(char const *str)
{
    char *copy = malloc(sizeof(char) * ib_strlen(str));
    int i = 0;

    for (; str[i] != '\0'; i++)
        copy[i] = str[i];
    copy[i] = '\0';
    return (copy);
}