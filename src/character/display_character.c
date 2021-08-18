/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** display_character
*/

#include "rpg_headers.h"

void display_character(game_t *game)
{
    sfSprite_setTextureRect(game->player->spider->sprite,\
        game->player->spider->rect);
    display_sprite(game->player->spider, game->window);
}