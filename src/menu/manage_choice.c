/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** manage_choice
*/

#include "rpg_headers.h"

void mouse_on_ch(choose_sprite_t *ch, sfVector2i mp)
{
    ch->bg_button1->rect.left = 256 *\
        ((mp.x < 238 && mp.x > 30) && (mp.y < 502 && mp.y > 291));
    ch->bg_button2->rect.left = 256 *\
        ((mp.x < 551 && mp.x > 340) && (mp.y < 502 && mp.y > 291));
    ch->bg_button3->rect.left = 256 *\
        ((mp.x < 863 && mp.x > 648) && (mp.y < 502 && mp.y > 291));
    sfSprite_setTextureRect(ch->bg_button1->sprite, ch->bg_button1->rect);
    sfSprite_setTextureRect(ch->bg_button2->sprite, ch->bg_button2->rect);
    sfSprite_setTextureRect(ch->bg_button3->sprite, ch->bg_button3->rect);
}

void click_on_ch(game_t *game, sfVector2i mp)
{
    if ((mp.x < 238 && mp.x > 30) && (mp.y < 502 && mp.y > 291)) {
        game->game_mode = 1;
        game->player->species = 0;
        change_character(game);
    }
    if ((mp.x < 551 && mp.x > 340) && (mp.y < 502 && mp.y > 291)) {
        game->game_mode = 1;
        game->player->species = 2;
        change_character(game);
    }
    if ((mp.x < 863 && mp.x > 648) && (mp.y < 502 && mp.y > 291)) {
        game->game_mode = 1;
        game->player->species = 1;
        change_character(game);
    }
}

void check_choice(game_t *game)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(game->window);

    mouse_on_ch(game->menu->ch, mp);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        click_on_ch(game, mp);
}