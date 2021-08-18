/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_settings
*/

#include "rpg_headers.h"
#include <stdlib.h>

void load_settings(game_t *game)
{
    sfIntRect rect = (sfIntRect){0, 0, 132, 99};
    game->menu->setting = malloc(sizeof(settings_t));

    game->menu->setting->is_open = false;
    game->menu->setting->buttonp = init_sprite("resources/menu/button+.png",\
        rect);
    game->menu->setting->buttonm = init_sprite("resources/menu/button-.png",\
        rect);
    game->menu->setting->bg = init_sprite("resources/menu/settings.png", rect);
    game->menu->setting->buttonm->pos = (sfVector2f){180, 340};
    game->menu->setting->buttonp->pos = (sfVector2f){600, 340};
    sfSprite_setTextureRect(game->menu->setting->buttonm->sprite,\
        game->menu->setting->buttonm->rect);
    sfSprite_setTextureRect(game->menu->setting->buttonp->sprite,\
        game->menu->setting->buttonp->rect);
}