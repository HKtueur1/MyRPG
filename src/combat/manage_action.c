/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_action
*/

#include "rpg_headers.h"

void action_fight(game_t *game, sfVector2i mp)
{
    if ((mp.x < 235 && mp.x > 60) && (mp.y < 670 && mp.y > 600)) {
        game->combat->scene->b_fight->rect.left = 500;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->combat->scene->b_fight->rect.left += 500;
            game->combat->mode = 0;
            sfSleep(game->combat->wait);
        }
    }
    sfSprite_setTextureRect(game->combat->scene->b_fight->sprite,\
        game->combat->scene->b_fight->rect);
    game->combat->scene->b_fight->rect.left = 0;
}

void action_bag(game_t *game, sfVector2i mp)
{
    if ((mp.x < 530 && mp.x > 315) && (mp.y < 670 && mp.y > 600)) {
        game->combat->scene->b_bag->rect.left = 500;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->combat->scene->b_bag->rect.left += 500;
            game->menu->inv->display = true;
            if (game->combat->mode == 2)
                game->combat->mode = 0;
            else
                game->combat->mode = 2;
        }
    }
    sfSprite_setTextureRect(game->combat->scene->b_bag->sprite,\
        game->combat->scene->b_bag->rect);
    game->combat->scene->b_bag->rect.left = 0;
}

void action_run(game_t *game, sfVector2i mp)
{
    if ((mp.x < 840 && mp.x > 640) && (mp.y < 670 && mp.y > 600)) {
        game->combat->scene->b_run->rect.left = 500;

        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->combat->scene->b_run->rect.left += 500;
            game->game_mode = 1;
            game->combat->cycle = 0;
        }
    }
    sfSprite_setTextureRect(game->combat->scene->b_run->sprite,\
        game->combat->scene->b_run->rect);
    game->combat->scene->b_run->rect.left = 0;
}

void manage_action(game_t *game)
{   
    sfVector2i mp = sfMouse_getPositionRenderWindow(game->window);
    void (*action_modules[4])(game_t *game, sfVector2i mp) =\
        {action_fight, action_bag, action_run};

    for (int i = 0; i < 3; i++)
        (*action_modules[i])(game, mp);
}