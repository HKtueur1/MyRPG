/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** cut_scene
*/

#include "rpg_headers.h"
#include <stdlib.h>

void display_cutscene(game_t *game)
{
    display_sprite(game->menu->cutscene->cut, game->window);
}

void display_endcutscene(game_t *game)
{
    display_sprite(game->menu->cutscene->end, game->window);
}

void load_cutscene(game_t *game)
{
    game->menu->cutscene->cut = init_sprite("resources/menu/storysheet.png",\
        (sfIntRect){0,0,0,0});
    game->menu->cutscene->end = init_sprite("resources/menu/end.png",\
        (sfIntRect){0,0,0,0});
    game->menu->cutscene->clock = sfClock_create();
}

void check_cutscene(game_t *game)
{
    game->menu->cutscene->time =\
        sfClock_getElapsedTime(game->menu->cutscene->clock);
    if (sfTime_asMicroseconds(game->menu->cutscene->time) > 1) {
        game->menu->cutscene->cut->pos.x -= 1;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->menu->current_menu = 1;
        if (game->menu->cutscene->cut->pos.x < -1800)
            game->menu->current_menu = 1;
        sfClock_restart(game->menu->cutscene->clock);
    }
}

void check_endcutscene(game_t *game)
{
//restart clock before MARK
    game->menu->cutscene->time =\
        sfClock_getElapsedTime(game->menu->cutscene->clock);
    if (sfTime_asMicroseconds(game->menu->cutscene->time) > 1) {
        game->menu->cutscene->end->pos.x -= 1;
        if (game->menu->cutscene->end->pos.x < -1800)
            game->menu->current_menu = 1;
        sfClock_restart(game->menu->cutscene->clock);
    }
}