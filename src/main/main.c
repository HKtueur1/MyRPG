/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** main
*/

#include "rpg_headers.h"

int main(int ac, char const * const av[])
{
    game_t game;
    int exit_status = error_handler(ac, av);

    if (exit_status == 84 || exit_status == 0)
        return (exit_status);
    if (!init_game(&game)) {
        end_game(&game);
        return (84);
    }
    launch_game(&game);
    end_game(&game);
    return (0);
}