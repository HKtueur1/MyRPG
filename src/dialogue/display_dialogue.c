/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** display_dialogue
*/

#include "ib.h"
#include "rpg_headers.h"

void display_dialogue(game_t *game)
{
    manage_dialogue(game);
    display_sprite(game->menu->diag->bg, game->window);
    sfRenderWindow_drawText(game->window, game->menu->diag->text, NULL);
}