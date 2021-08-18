/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_menu
*/

#include "ib.h"
#include "rpg_headers.h"
#include <stdlib.h>

static void pos_sprite_bg(bg_sprite_t *bg, choose_sprite_t *ch)
{
    bg->play->pos = (sfVector2f){300, 215};
    bg->exit->pos = (sfVector2f){300, 515};
    bg->htp->pos = (sfVector2f){300, 315};
    bg->settings->pos = (sfVector2f){300, 415};
    ch->bg_button1->pos = (sfVector2f) {10, 270};
    ch->bg_button2->pos = (sfVector2f) {320, 270};
    ch->bg_button3->pos = (sfVector2f) {630, 270};
    sfSprite_setTextureRect(bg->play->sprite, bg->play->rect);
    sfSprite_setTextureRect(bg->exit->sprite, bg->exit->rect);
    sfSprite_setTextureRect(bg->htp->sprite, bg->htp->rect);
    sfSprite_setTextureRect(bg->settings->sprite, bg->settings->rect);
    sfSprite_setTextureRect(ch->bg_button1->sprite, ch->bg_button1->rect);
    sfSprite_setTextureRect(ch->bg_button2->sprite, ch->bg_button2->rect);
    sfSprite_setTextureRect(ch->bg_button3->sprite, ch->bg_button3->rect);
}

static void create_sprite(bg_sprite_t *bg, choose_sprite_t *ch, game_t *game)
{
    sfIntRect rect = (sfIntRect){0, 0, 322, 96};

    bg->background = init_sprite("resources/menu/bg_spider.png", rect);
    bg->exit = init_sprite("resources/menu/button_exit.png", rect);
    bg->htp = init_sprite("resources/menu/button_htp.png", rect);
    bg->settings = init_sprite("resources/menu/button_settings.png", rect);
    bg->play = init_sprite("resources/menu/button_play.png", rect);
    bg->how = init_sprite("resources/menu/how.png", rect);
    rect = (sfIntRect){0, 0, 256, 256};
    ch->bg = init_sprite("resources/menu/bg_choose.png", rect);
    ch->bg_button1 = init_sprite("resources/menu/button1.png", rect);
    ch->bg_button2 = init_sprite("resources/menu/button2.png", rect);
    ch->bg_button3 = init_sprite("resources/menu/button3.png", rect);
    rect = (sfIntRect){0, 0, 0, 0};
    game->color->white = init_sprite("resources/character/player1.png", rect);
    game->color->violet = init_sprite("resources/character/player2.png", rect);
    game->color->blue = init_sprite("resources/character/player3.png", rect);
    pos_sprite_bg(bg, ch);
}

bool load_menu(game_t *game)
{
    ib_putstr("Loading menus ...\n");
    game->menu = malloc(sizeof(menu_t));
    game->menu->current_menu = 0;
    game->menu->bg = malloc(sizeof(bg_sprite_t));
    game->menu->inv = malloc(sizeof(inventory_sprite_t));
    game->menu->nb_inv = malloc(sizeof(nb_inv_t));
    game->menu->ch = malloc(sizeof(choose_sprite_t));
    game->color = malloc(sizeof(spd_sprite_t));
    game->menu->pause = malloc(sizeof(pause_menu_t));
    game->menu->cutscene = malloc(sizeof(cutscene_t));
    game->menu->bg->exit = false;
    game->menu->bg->how_isopen = false;
    create_sprite(game->menu->bg, game->menu->ch, game);
    create_inventory(game);
    create_pause(game);
    load_settings(game);
    music(game);
    load_cutscene(game);
    ib_putstr("[SUCCESS]\n");
    return (true);
}