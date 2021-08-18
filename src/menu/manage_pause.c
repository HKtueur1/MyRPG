/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_menu2
*/

#include "rpg_headers.h"

void click_on_pause(game_t *game)
{
    if (sprite_hover(game->menu->pause->b_menu, game->window)) {
        destroy_sprite(game->world->map);
        free(game->world);
        load_world(game);
    }
    if (sprite_hover(game->menu->pause->b_exit, game->window)) {
        free_music(game);
        sfRenderWindow_close(game->window);
    }
}

void mouse_on_pause(game_t *game)
{
    if (sprite_hover(game->menu->pause->b_menu, game->window))
        game->menu->pause->b_menu->rect.left = 292;
    if (sprite_hover(game->menu->pause->b_exit, game->window))
        game->menu->pause->b_exit->rect.left = 292;
    sfSprite_setTextureRect(game->menu->pause->b_menu->sprite,\
        game->menu->pause->b_menu->rect);
    sfSprite_setTextureRect(game->menu->pause->b_exit->sprite,\
        game->menu->pause->b_exit->rect);
    game->menu->pause->b_menu->rect.left = 0;
    game->menu->pause->b_exit->rect.left = 0;
}

void check_pause(game_t * game)
{
    mouse_on_pause(game);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        click_on_pause(game);
    if (sfKeyboard_isKeyPressed(sfKeyA))
        game->game_mode = game->menu->pause->prev_mode;
        
}