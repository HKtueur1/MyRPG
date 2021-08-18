/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_character
*/

#include "ib.h"
#include "rpg_map.h"
#include "rpg_headers.h"

bool animate_player(game_t *game)
{
    game->player->time = sfClock_getElapsedTime(game->combat->clock);
    if (game->player->time.microseconds > 100000) {
        game->player->spider->rect.left += 80;
        if (game->player->spider->rect.left > 160)
            game->player->spider->rect.left = 0;
        sfClock_restart(game->combat->clock);
    }
    return (0);
}

bool move_z(game_t *game)
{
    int x = game->world->pos.x;
    int y = game->world->pos.y - 3;
    int lvl = game->world->level;

    game->player->spider->rect.top = 192;
    if (map[lvl][y / 64][x / 64] != 'x') {
        if (game->player->spider->rect.left > 160)
            game->player->spider->rect.left = 0;
        game->world->pos.y -= 3;
        if (y > 176 && y < 464)
            move_sprite(game->world->map, 'd');
        else
            move_sprite(game->player->spider, 'u');
    }
    return (0);
}

bool move_d(game_t *game)
{
    int x = game->world->pos.x + 3;
    int y = game->world->pos.y;
    int lvl = game->world->level;

    game->player->spider->rect.top = 128;
    if (map[lvl][y / 64][x / 64] != 'x') {
        if (game->player->spider->rect.left > 160)
            game->player->spider->rect.left = 0;
        game->world->pos.x += 3;
        if (x > 224 && x < ib_atoi(map[lvl][12]))
            move_sprite(game->world->map, 'l');
        else
            move_sprite(game->player->spider, 'r');
    }
    return (0);
}

bool move_s(game_t *game)
{
    int x = game->world->pos.x;
    int y = game->world->pos.y + 3;
    int lvl = game->world->level;

    game->player->spider->rect.top = 0;
    if (map[lvl][y / 64][x / 64] != 'x') {
        if (game->player->spider->rect.left > 160)
            game->player->spider->rect.left = 0;
        game->world->pos.y += 3;
        if (y > 176 && y < 464)
            move_sprite(game->world->map, 'u');
        else
            move_sprite(game->player->spider, 'd');
    }
    return (0);
}

bool move_q(game_t *game)
{
    int x = game->world->pos.x - 3;
    int y = game->world->pos.y;
    int lvl = game->world->level;

    game->player->spider->rect.top = 64;
    if (map[lvl][y / 64][x / 64] != 'x') {
        if (game->player->spider->rect.left > 160)
            game->player->spider->rect.left = 0;
        game->world->pos.x -= 3;
        if (x > 224 && x < ib_atoi(map[lvl][12]))
            move_sprite(game->world->map, 'r');
        else
            move_sprite(game->player->spider, 'l');
    }
    return (0);
}