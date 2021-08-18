/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** display_combat
*/

#include "ib.h"
#include "rpg_headers.h"
#include <stdio.h>

void animation(enemy_t *enemy, game_t *game)
{
    game->combat->time = sfClock_getElapsedTime(game->combat->clock);
    if (game->combat->time.microseconds > 100000) {
        enemy->sprite->rect.left += enemy->move_rect;
        if (enemy->sprite->rect.left >= enemy->rect_end)
            enemy->sprite->rect.left = 0;
        sfSprite_setTextureRect(enemy->sprite->sprite, enemy->sprite->rect);
        sfClock_restart(game->combat->clock);
    }
    display_sprite(enemy->sprite, game->window);
}

void display_fight(game_t *game)
{
    display_sprite(game->combat->scene->attack[0], game->window);
    display_sprite(game->combat->scene->attack[1], game->window);
    display_sprite(game->combat->scene->attack[2], game->window);
}

void display_action(game_t *game)
{
    display_sprite(game->combat->scene->b_bag, game->window);
    display_sprite(game->combat->scene->b_fight, game->window);
    display_sprite(game->combat->scene->b_run, game->window);
}

void display_combat(game_t *game)
{
    void (*action_modules[4])(game_t *game) =\
        {display_fight, display_action, display_inv};

// ici mias pas ici MARK
    if (game->combat->cycle == 0)
        game->combat->enemy = load_enemy_c(game->combat->enemy,\
            (((game->world->level - 1) * 2) + game->combat->boss));
    game->combat->cycle = 1;
// FIN
    display_sprite(game->combat->scene->background, game->window);
    display_sprite(game->combat->enemy->health, game->window);
    display_sprite(game->player->health_bar, game->window);
    animation(game->combat->enemy, game);
    (*action_modules[game->combat->mode])(game);
}