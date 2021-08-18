/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** display_menu
*/

#include "ib.h"
#include "rpg_headers.h"

void display_inv(game_t *game)
{
    display_sprite(game->menu->inv->bg, game->window);
    display_sprite(game->menu->inv->stinger, game->window);
    display_sprite(game->menu->inv->potion, game->window);
    display_sprite(game->menu->inv->cocoon, game->window);
    display_sprite(game->menu->inv->sting, game->window);
    display_sprite(game->menu->inv->silk, game->window);
    display_sprite(game->menu->inv->bite, game->window);
}

void display_pause(game_t *game)
{
    display_sprite(game->menu->pause->bg, game->window);
    display_sprite(game->menu->pause->b_menu, game->window);
    display_sprite(game->menu->pause->b_exit, game->window);
}

void display_choice(game_t *game)
{
    display_sprite(game->menu->ch->bg, game->window);
    display_sprite(game->menu->ch->bg_button1, game->window);
    display_sprite(game->menu->ch->bg_button2, game->window);
    display_sprite(game->menu->ch->bg_button3, game->window);
}

void display_start(game_t *game)
{
    display_sprite(game->menu->bg->background, game->window);
    display_sprite(game->menu->bg->settings, game->window);
    display_sprite(game->menu->bg->play, game->window);
    display_sprite(game->menu->bg->exit, game->window);
    display_sprite(game->menu->bg->htp, game->window);
    if (game->menu->bg->how_isopen)
        display_sprite(game->menu->bg->how, game->window);
    if (game->menu->setting->is_open)
        display_setting(game);
}

void display_menu(game_t *game)
{
    void (*check_module[6])(game_t *game) =\
        {display_start, display_choice, display_pause,\
        display_cutscene, display_endcutscene};

    (*check_module[game->menu->current_menu])(game);
}