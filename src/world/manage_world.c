/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_world
*/

#include "ib.h"
#include "rpg_map.h"
#include "rpg_headers.h"

bool manage_interaction(game_t *game)
{
    int x = game->world->pos.x / 64;
    int y = game->world->pos.y / 64;

    if (map[game->world->level][y][x] == 'E')
        for (int i = 0; i < 4; i++)
            if (y == game->world->eve[i]) {
                game->world->eve[i] = 0;
                game->combat->boss = false;
                game->game_mode = 2;
            }
    if (map[game->world->level][y][x] == 'B' && game->world->boss) {
        game->world->boss = false;
        game->combat->boss = true;
        game->game_mode = 2;
    }
    if (map[game->world->level][y][x] == '+' && game->world->dialogue) {
        game->world->speaking = true;
        return (true);
    }
    return (false);
}

bool manage_inventory(game_t *game)
{
    if (game->menu->inv->display)
        check_inv(game);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        game->menu->inv->display = true;
    if (sfKeyboard_isKeyPressed(sfKeyJ))
        game->menu->inv->display = false;
    return (game->menu->inv->display);
}

bool manage_move(game_t *game)
{
    if ((game->world->pos.y - 6) / 64 < 0 ||\
        (game->world->pos.x - 6) / 64 < 0) {
            if (!load_next_level(game))
            ib_puterr("Failed to load next level\n", 0);
        return (true);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        return (move_z(game) + animate_player(game));
    if (sfKeyboard_isKeyPressed(sfKeyD))
        return (move_d(game) + animate_player(game));
    if (sfKeyboard_isKeyPressed(sfKeyS))
        return (move_s(game) + animate_player(game));
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        return (move_q(game) + animate_player(game));
    return (false);
}

bool manage_position(game_t *game)
{
    if ((game->world->pos.y - 8) / 64 < 0 ||\
        (game->world->pos.x - 8) / 64 < 0) {
        if (!load_next_level(game))
            ib_puterr("Failed to load next level\n", 0);
        return (true);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->menu->pause->prev_mode = game->game_mode;
        game->menu->current_menu = 2;
        game->game_mode = 0;
    }
    return (false);
}

void manage_world(game_t *game)
{
    bool (*world_modules[5])(game_t *game) =\
        {manage_interaction, manage_inventory, manage_move, manage_position};

    for (int i = 0; i < 3; i++)
        if ((*world_modules[i])(game))
            return;
}