/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_combat
*/

#include "rpg_headers.h"

void update_health(sprite_t *sprite, double hp, double hp_max)
{
    sfIntRect rect = (sfIntRect){0, 0, \
        sprite->rect.width, sprite->rect.height};
    double result = 0;
    double length = sprite->rect.width;
    int width = 0;

    result = (hp / hp_max);
    length *= result;
    width = length;
    rect.width = width;
    if (hp < 0)
        rect.width = 0;
    sfSprite_setTextureRect(sprite->sprite, rect);
}

void manage_combat(game_t *game)
{
    void (*combat_modules[3])(game_t *game) =\
    {manage_fight, manage_action, check_inv};

    (*combat_modules[game->combat->mode])(game);
    update_health(game->player->health_bar, game->player->hp, game->player->hp_max);
    update_health(game->combat->enemy->health, game->combat->enemy->hp, game->combat->enemy->hp_max);
}