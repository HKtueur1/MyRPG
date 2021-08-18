/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_menu
*/

#include "rpg_headers.h"

void check_void(__attribute__((unused))game_t *game)
{
    return;
}

void mouse_on_button(bg_sprite_t *bg, sfVector2i mp)
{
    bg->settings->rect.left = 322 *\
        ((mp.x < 600 && mp.x > 320) && (mp.y < 496 && mp.y > 431));
    bg->play->rect.left = 322 *\
        ((mp.x < 600 && mp.x > 320) && (mp.y < 297 && mp.y > 231));
    bg->exit->rect.left = 322 *\
        ((mp.x < 600 && mp.x > 320) && (mp.y < 592 && mp.y > 533));
    bg->htp->rect.left = 322 *\
        ((mp.x < 600 && mp.x > 320) && (mp.y < 393 && mp.y > 329));
    sfSprite_setTextureRect(bg->settings->sprite, bg->settings->rect);
    sfSprite_setTextureRect(bg->play->sprite, bg->play->rect);
    sfSprite_setTextureRect(bg->exit->sprite, bg->exit->rect);
    sfSprite_setTextureRect(bg->htp->sprite, bg->htp->rect);
}

void click_on_button(game_t *game, sfVector2i mp)
{
    if ((mp.x < 600 && mp.x > 320) && (mp.y < 297 && mp.y > 231)) {
        game->menu->current_menu = 3;
        sfClock_restart(game->menu->cutscene->clock);
    }
    if ((mp.x < 600 && mp.x > 320) && (mp.y < 496 && mp.y > 431))
        game->menu->setting->is_open = true;
    if ((mp.x < 600 && mp.x > 320) && (mp.y < 393 && mp.y > 329))
        game->menu->bg->how_isopen = true;
    if ((mp.x < 600 && mp.x > 320) && (mp.y < 592 && mp.y > 533)) {
        free_music(game);
        sfRenderWindow_close(game->window);
    }
}

void check_menu(game_t *game)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(game->window);
    
    mouse_on_button(game->menu->bg, mp);
    mouse_on_settings(game);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        click_on_button(game, mp);
        click_on_settings(game);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->menu->bg->how_isopen = false;
        game->menu->setting->is_open = false;
    }
}

void manage_menu(game_t *game)
{
    void (*check_module[6])(game_t *game) =\
    {check_menu, check_choice, check_pause, check_cutscene, check_endcutscene};

    (*check_module[game->menu->current_menu])(game);
}