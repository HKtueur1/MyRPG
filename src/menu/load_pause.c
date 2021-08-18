/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_menu2
*/

#include "rpg_headers.h"
#include <stdlib.h>

void create_pause(game_t *game) 
{
    sfIntRect rect = (sfIntRect){0, 0, 292, 111};

    game->menu->pause = malloc(sizeof(pause_menu_t));
    game->menu->pause->bg = init_sprite("resources/menu/pause_1.png", rect);
    game->menu->pause->b_menu = init_sprite("resources/menu/menu_button.png",\
        rect);
    game->menu->pause->b_exit = init_sprite("resources/menu/exit_button.png",\
        rect);
    game->menu->pause->b_exit->pos = (sfVector2f) {320, 470};
    game->menu->pause->b_menu->pos = (sfVector2f) {320, 300};
    sfSprite_setTextureRect(game->menu->pause->b_exit->sprite,\
        game->menu->pause->b_exit->rect);
    sfSprite_setTextureRect(game->menu->pause->b_menu->sprite,\
        game->menu->pause->b_menu->rect);
}