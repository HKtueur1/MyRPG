/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** window_event
*/

#include "ib.h"
#include "rpg_map.h"
#include "rpg_headers.h"

void check_event(game_t *game)
{
    void (*manage_module[5])(game_t *game) =\
    {manage_menu, manage_world, manage_combat, manage_dialogue};

    while (sfRenderWindow_pollEvent(game->window, &game->event))
        if (game->event.type == sfEvtClosed)
            return (sfRenderWindow_close(game->window));
    (*manage_module[game->game_mode])(game);
}