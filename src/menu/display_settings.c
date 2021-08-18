/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** display_settings
*/

#include "rpg_headers.h"

void display_setting(game_t *game)
{
    display_sprite(game->menu->setting->bg, game->window);
    display_sprite(game->menu->setting->buttonp, game->window);
    display_sprite(game->menu->setting->buttonm, game->window);
}

void mouse_on_settings(game_t *game)
{
    if (sprite_hover(game->menu->setting->buttonm, game->window))
        game->menu->setting->buttonm->rect.left = 132;
    if (sprite_hover(game->menu->setting->buttonp, game->window))
        game->menu->setting->buttonp->rect.left = 132;
    sfSprite_setTextureRect(game->menu->setting->buttonp->sprite,\
        game->menu->setting->buttonp->rect);
    sfSprite_setTextureRect(game->menu->setting->buttonm->sprite,\
        game->menu->setting->buttonm->rect);
        game->menu->setting->buttonm->rect.left = 0;
        game->menu->setting->buttonp->rect.left = 0;
}

void click_on_settings(game_t *game)
{
    if (sprite_hover(game->menu->setting->buttonm, game->window) && game->music->vol > 0) {
        game->music->vol -= 5;
        sfMusic_setVolume(game->music->main, game->music->vol);
        sfMusic_setVolume(game->music->combat, game->music->vol);
    }
    if (sprite_hover(game->menu->setting->buttonp, game->window) && game->music->vol < 100) {
        game->music->vol += 5;
        sfMusic_setVolume(game->music->main, game->music->vol);
        sfMusic_setVolume(game->music->combat, game->music->vol);
    }
}