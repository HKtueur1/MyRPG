/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** launch_game
*/

#include "rpg_headers.h"

bool launch_game(game_t *game)
{
    void (*display_window[4])(game_t *game) = \
    {display_menu, display_world, display_combat};

    while (sfRenderWindow_isOpen(game->window)) {
        check_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        (*display_window[game->game_mode])(game);
        sfRenderWindow_display(game->window);
    }
    return (true);
}