/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** display_world
*/

#include "ib.h"
#include "rpg_headers.h"

void display_world(game_t *game)
{
    display_sprite(game->world->map, game->window);
    display_character(game);
    if (game->menu->inv->display)
        display_inv(game);
    if (game->world->speaking)
        display_dialogue(game);
}