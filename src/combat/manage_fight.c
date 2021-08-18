/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** manage_fight
*/

#include "rpg_headers.h"

void check_dead(game_t *game)
{
    if (game->combat->enemy->hp <= 0) {
        game->combat->cycle = 0;
        game->player->xp += game->combat->enemy->xp;
        if (game->player->xp >= game->player->lv_up) {
            game->player->hp_max += 20;
            game->player->hp = game->player->hp_max;
            game->player->def += 5;
            game->player->xp -= 10;
        }
        game->game_mode = 1;
    }
}

void bite_attack(game_t *game, sprite_t *attack, scene_c_t *scene)
{
    if (sprite_hover(attack, game->window)) {
        attack->rect.left = 221;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            attack->rect.left = 442;
            game->combat->enemy->hp -= game->player->atk;
            game->player->hp -= (game->combat->enemy->atk - game->player->def);
            game->combat->mode = 1;
            display_sprite(scene->yellow, game->window);
            sfRenderWindow_display(game->window);
            sfSleep(game->combat->wait);
        }
    }
    sfSprite_setTextureRect(attack->sprite, attack->rect);
    attack->rect.left = 0;
}

void shield_attack(game_t *game, sprite_t *attack, scene_c_t *scene)
{
    if (sprite_hover(attack, game->window)) {
        attack->rect.left = 221;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            attack->rect.left = 442;
            game->player->hp -= (game->combat->enemy->atk - game->player->def);
            game->combat->mode = 1;
            sfSleep(game->combat->wait);
        }
    }
    sfSprite_setTextureRect(attack->sprite, attack->rect);
    attack->rect.left = 0;
}

void sting_attack(game_t *game, sprite_t *attack, scene_c_t *scene)
{
    if (sprite_hover(attack, game->window)) {
        attack->rect.left = 221;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            attack->rect.left = 442;
            game->combat->enemy->hp -= (game->player->atk * 2);
            game->player->hp -= (game->combat->enemy->atk - game->player->def);
            game->combat->mode = 1;
            display_sprite(scene->red, game->window);
            sfRenderWindow_display(game->window);
            sfSleep(game->combat->wait);
        }
    }
    sfSprite_setTextureRect(attack->sprite, attack->rect);
    attack->rect.left = 0;
}

void manage_fight(game_t *game)
{
    void (*fight_modules[4])\
        (game_t *game, sprite_t **attack, scene_c_t *scene) =\
        {bite_attack, shield_attack, sting_attack};

    for (int i = 0; i < 3; i++) {
        (*fight_modules[i])\
        (game, game->combat->scene->attack[i], game->combat->scene);
    }
    check_dead(game);
}