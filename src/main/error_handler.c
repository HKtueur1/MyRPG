/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** error_handler
*/

#include "rpg_errors.h"
#include "ib.h"

int error_handler(int ac, char const * const av[])
{
    if (ac != 1 && ac != 2)
        return (ib_puterr(error[2], 84));
    if (ac == 2) {
        if (ib_strcmp(av[1], "-h"))
            return (ib_puterr(error[0], 0));
        else {
            ib_puterr("Error: '", 84);
            ib_puterr(av[1], 84);
            return (ib_puterr(error[3], 84));
        }
    }
    return (1);
}