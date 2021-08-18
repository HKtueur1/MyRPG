/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_inventory
*/

#include "rpg_headers.h"

void mouse_on_inv(game_t *game)
{
    if (sprite_hover(game->menu->inv->potion, game->window))
        game->menu->inv->potion->rect.top = 117;
    if (sprite_hover(game->menu->inv->cocoon, game->window))
        game->menu->inv->cocoon->rect.top = 111;
    if (sprite_hover(game->menu->inv->stinger, game->window))
        game->menu->inv->stinger->rect.top = 97;
    sfSprite_setTextureRect(game->menu->inv->potion->sprite,\
        game->menu->inv->potion->rect);
    sfSprite_setTextureRect(game->menu->inv->cocoon->sprite,\
        game->menu->inv->cocoon->rect);
    sfSprite_setTextureRect(game->menu->inv->stinger->sprite,\
        game->menu->inv->stinger->rect);
    game->menu->inv->potion->rect.top = 0;
    game->menu->inv->cocoon->rect.top = 0;
    game->menu->inv->stinger->rect.top = 0;
}

void click_on_inv(game_t *game)
{
    if (sprite_hover(game->menu->inv->potion, game->window)) {
        game->player->hp += 50;
        game->combat->mode = 1;
    }
    if (sprite_hover(game->menu->inv->cocoon, game->window)) {
        game->player->def += 5;
        game->combat->mode = 1;
    }
    if (sprite_hover(game->menu->inv->stinger, game->window)) {
        game->player->atk += 5;
        game->combat->mode = 1;
    }
}

void check_inv(game_t *game)
{
    mouse_on_inv(game);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        click_on_inv(game);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->combat->mode = 1;
        game->menu->inv->display = false;
    }
}